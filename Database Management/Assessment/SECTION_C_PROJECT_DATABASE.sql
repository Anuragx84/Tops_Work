-- Mini Project:  Food Delivery Platform — Backend Database
-- Objective: Build the complete backend database for a Food Delivery application, combining DDL, DML, JOINs, Views, and PL/SQL into a single integrated .sql script.
-- Your project must:
/*Create three tables: restaurants (restaurant_id, name, city, cuisine_type, created_at),
menu_items (item_id, restaurant_id, item_name, price, category) with a FOREIGN KEY on
restaurant_id, and orders (order_id, customer_name, restaurant_id, item_id, quantity,
total_amount, order_date) with a FOREIGN KEY on restaurant_id — all with appropriate
PRIMARY KEY and NOT NULL constraints.*/
CREATE DATABASE IF NOT EXISTS foodapp_db1;
USE foodapp_db1;

CREATE TABLE restaurants (
    restaurant_id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    city VARCHAR(50) NOT NULL,
    cuisine_type VARCHAR(50) NOT NULL,
    created_at DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE menu_items (
    item_id INT AUTO_INCREMENT PRIMARY KEY,
    restaurant_id INT NOT NULL,
    item_name VARCHAR(100) NOT NULL,
    price DECIMAL(10,2) NOT NULL,
    category VARCHAR(50) NOT NULL,
    FOREIGN KEY (restaurant_id)
        REFERENCES restaurants(restaurant_id)
);

CREATE TABLE orders (
    order_id INT AUTO_INCREMENT PRIMARY KEY,
    customer_name VARCHAR(100) NOT NULL,
    restaurant_id INT NOT NULL,
    item_id INT NOT NULL,
    quantity INT NOT NULL,
    total_amount DECIMAL(10,2) NOT NULL,
    order_date DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (restaurant_id)
        REFERENCES restaurants(restaurant_id),
    FOREIGN KEY (item_id)
        REFERENCES menu_items(item_id)
);
-- Populate with at least 3 restaurants, 4 menu categories, and 15 order records distributed across restaurants.
INSERT INTO restaurants (name, city, cuisine_type)
VALUES
('Sharma Dhaba', 'Neemuch', 'Indian'),
('Pizza House', 'Indore', 'Italian'),
('Dragon Wok', 'Bhopal', 'Chinese');

INSERT INTO menu_items
(restaurant_id, item_name, price, category)
VALUES
(1, 'Paneer Tikka', 250, 'Starter'),
(1, 'Dal Fry', 180, 'Main Course'),
(1, 'Butter Roti', 20, 'Bread'),
(1, 'Cold Coffee', 120, 'Beverage'),
(1, 'Veg Biryani', 220, 'Main Course'),
(2, 'Margherita Pizza', 299, 'Main Course'),
(2, 'Garlic Bread', 149, 'Starter'),
(2, 'Cold Coffee', 120, 'Beverage'),
(2, 'Pasta', 250, 'Main Course'),
(2, 'Brownie', 100, 'Dessert'),
(3, 'Veg Noodles', 180, 'Main Course'),
(3, 'Spring Roll', 150, 'Starter'),
(3, 'Fried Rice', 200, 'Main Course'),
(3, 'Ice Cream', 90, 'Dessert'),
(3, 'Lemon Soda', 60, 'Beverage');

INSERT INTO orders
(customer_name, restaurant_id, item_id, quantity, total_amount)
VALUES
('Amit', 1, 1, 2, 500),
('Rahul', 1, 2, 1, 180),
('Priya', 1, 3, 4, 80),
('Neha', 1, 4, 2, 240),
('Rohit', 1, 5, 1, 220),
('Pooja', 2, 6, 2, 598),
('Vikas', 2, 7, 1, 149),
('Sneha', 2, 8, 2, 240),
('Karan', 2, 9, 1, 250),
('Anjali', 2, 10, 2, 200),
('Deepak', 3, 11, 2, 360),
('Simran', 3, 12, 1, 150),
('Mohit', 3, 13, 2, 400),
('Kavita', 3, 14, 3, 270),
('Arjun', 3, 15, 2, 120);

-- Create a VIEW named restaurant_sales_summary showing restaurant name, total number of orders, and total revenue grouped by restaurant.
CREATE OR REPLACE VIEW restaurant_sales_summary AS
SELECT
    r.name AS restaurant_name,
    COUNT(o.order_id) AS total_orders,
    SUM(o.total_amount) AS total_revenue
FROM restaurants r
LEFT JOIN orders o
    ON r.restaurant_id = o.restaurant_id
GROUP BY r.restaurant_id, r.name;

SELECT * FROM restaurant_sales_summary;

/*Write a stored procedure named add_order that accepts customer_name, restaurant_id,
item_id, and quantity, calculates total_amount from the menu item price, validates the
restaurant exists (ROLLBACK if not), and inserts the order record.*/
DELIMITER //

CREATE PROCEDURE add_order(
    IN p_customer_name VARCHAR(100),
    IN p_restaurant_id INT,
    IN p_item_id INT,
    IN p_quantity INT
)
BEGIN
    DECLARE v_price DECIMAL(10,2);
    DECLARE v_count INT DEFAULT 0;

    START TRANSACTION;

    SELECT COUNT(*)
    INTO v_count
    FROM restaurants
    WHERE restaurant_id = p_restaurant_id;

    IF v_count = 0 THEN
        ROLLBACK;
    ELSE
        SELECT price
        INTO v_price
        FROM menu_items
        WHERE item_id = p_item_id
          AND restaurant_id = p_restaurant_id;

        INSERT INTO orders
        (customer_name, restaurant_id, item_id,
         quantity, total_amount, order_date)
        VALUES
        (p_customer_name, p_restaurant_id, p_item_id,
         p_quantity, v_price * p_quantity, NOW());

        COMMIT;
    END IF;
END //

DELIMITER ;

/*Write a TRIGGER named after_order_insert that logs a record into an order_audit table
(order_id, restaurant_id, action='INSERT', log_time=NOW()) immediately after every new order
is created.*/
CREATE TABLE order_audit (
    audit_id INT AUTO_INCREMENT PRIMARY KEY,
    order_id INT NOT NULL,
    restaurant_id INT NOT NULL,
    action VARCHAR(10) NOT NULL,
    log_time DATETIME NOT NULL
);
DELIMITER //

CREATE TRIGGER after_order_insert
AFTER INSERT ON orders
FOR EACH ROW
BEGIN
    INSERT INTO order_audit
    (order_id, restaurant_id, action, log_time)
    VALUES
    (NEW.order_id, NEW.restaurant_id, 'INSERT', NOW());
END //

DELIMITER ;
CALL add_order('Amit Sharma', 1, 1, 2);
CALL add_order('Rahul Verma', 99, 1, 2);
SELECT * FROM orders ORDER BY order_id DESC;
SELECT * FROM order_audit ORDER BY audit_id DESC;
SELECT * FROM restaurant_sales_summary;