-- Task 1: Design and Populate a Restaurant Database

/*Create a database named foodapp_db and a table named restaurants with columns:
restaurant_id (INT, AUTO_INCREMENT, PRIMARY KEY), name (VARCHAR, NOT NULL), city
(VARCHAR), cuisine_type (VARCHAR), and rating (DECIMAL(3,1)).*/
create database foodapp_db;
use foodapp_db;
create table restaurants (restaurant_id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(25) NOT NULL, city VARCHAR(20), cuisine_type VARCHAR(50), rating DECIMAL(3,1));

-- Insert at least 6 restaurant records spanning at least 3 different cities.
INSERT INTO restaurants (name, city, cuisine_type, rating)
VALUES
('Sharma Dhaba', 'Neemuch', 'Indian', 4.2),
('Pizza House', 'Indore', 'Italian', 4.5),
('Spice Garden', 'Bhopal', 'Indian', 4.0),
('Dragon Wok', 'Indore', 'Chinese', 4.3),
('Royal Bites', 'Neemuch', 'North Indian', 3.8),
('Food Junction', 'Ujjain', 'Fast Food', 4.1);

-- Update the rating of one restaurant and delete one restaurant record using a WHERE condition.
UPDATE restaurants SET rating = 4.0 WHERE restaurant_id = 1;

DELETE FROM restaurants WHERE restaurant_id = 4.1;

-- Write a SELECT query that retrieves all restaurants sorted by rating in descending order
SELECT * FROM restaurants ORDER BY rating DESC;

-- Taks2 
-- Create an orders table with columns: order_id, restaurant_id, customer_name, total_amount, and order_date. Insert at least 12 orders distributed across at least 4 restaurants.
CREATE TABLE orders (
	order_id INT PRIMARY KEY AUTO_INCREMENT,
    restaurant_id INT, 
    customer_name VARCHAR(20) NOT NULL, 
    total_amount INT ,order_date DATE,
    foreign key (restaurant_id) REFERENCES restaurants(restaurant_id)
    );
    
    INSERT INTO orders
(restaurant_id, customer_name, total_amount, order_date)
VALUES
(1, 'Amit Sharma', 450, '2026-10-01'),
(2, 'Rahul Verma', 800, '2026-10-02'),
(3, 'Priya Singh', 350, '2026-10-03'),
(4, 'Neha Jain', 600, '2026-10-04'),
(1, 'Rohit Patel', 700, '2026-10-05'),
(2, 'Pooja Mehta', 550, '2026-10-06'),
(3, 'Vikas Yadav', 900, '2026-10-07'),
(4, 'Sneha Gupta', 400, '2026-10-08'),
(1, 'Karan Joshi', 650, '2026-10-09'),
(2, 'Anjali Rao', 750, '2026-10-10'),
(3, 'Deepak Soni', 500, '2026-10-11'),
(4, 'Simran Khan', 850, '2026-10-12');
    

-- Write a query to show total revenue and average order value per restaurant.
SELECT restaurant_id, SUM(total_amount),AVG(total_amount) FROM orders GROUP BY restaurant_id;

-- Write a query using HAVING to list only restaurants whose total revenue exceeds Rs 5,000.
SELECT restaurant_id FROM orders GROUP BY restaurant_id HAVING SUM(total_amount) > 5000;

-- Write a query to retrieve the 5 most recent orders using ORDER BY and LIMIT.
SELECT * FROM orders ORDER BY order_date DESC LIMIT 5;

-- TASK 3
-- Create two tables: restaurants (restaurant_id, name, city) and menu_items (item_id,restaurant_id, item_name, price, category). Link them with a FOREIGN KEY on restaurant_id.
CREATE TABLE menu_items (
	item_id INT PRIMARY KEY,
    restaurant_id INT , 
    item_name VARCHAR(30), 
    price INT , 
    category VARCHAR(30),
    FOREIGN KEY (restaurant_id) REFERENCES restaurants(restaurant_id));
    
-- Insert at least 5 restaurants and 12 menu items; at least one restaurant must have no menu items.
INSERT INTO menu_items
(item_id, restaurant_id, item_name, price, category)
VALUES
(1, 1, 'Paneer Tikka', 250, 'Starter'),
(2, 1, 'Dal Fry', 180, 'Main Course'),
(3, 1, 'Butter Roti', 20, 'Bread'),
(4, 2, 'Margherita Pizza', 299, 'Pizza'),
(5, 2, 'Farmhouse Pizza', 399, 'Pizza'),
(6, 2, 'Garlic Bread', 149, 'Starter'),
(7, 3, 'Veg Biryani', 220, 'Main Course'),
(8, 3, 'Paneer Masala', 280, 'Main Course'),
(9, 3, 'Cold Coffee', 120, 'Beverage'),
(10, 4, 'Veg Noodles', 180, 'Main Course'),
(11, 4, 'Spring Roll', 150, 'Starter'),
(12, 4, 'Fried Rice', 200, 'Main Course');

-- Write an INNER JOIN query listing restaurant name, item name, and price for all available items.
SELECT name,item_name,price FROM restaurants INNER JOIN menu_items ON restaurants.restaurant_id = menu_items.restaurant_id;

-- Write a LEFT JOIN query so that restaurants with no items also appear in results, with NULL values in item columns.
SELECT * FROM restaurants LEFT JOIN menu_items ON restaurants.restaurant_id = menu_items.restaurant_id;

-- Create a VIEW named restaurant_menu_summary showing restaurant name, total number of menu items, and average item price grouped by restaurant.
CREATE VIEW restaurant_menu_summary as 
	SELECT r.name AS restaurant_name, COUNT(m.item_name) as total_item , AVG(price) as average_item_price 
    FROM restaurants r LEFT JOIN menu_items m ON r.restaurant_id = m.restaurant_id group  by r.restaurant_id, r.name;
select * from restaurant_menu_summary;

-- TASK 4
-- Create a stored procedure named place_order that accepts customer_id, restaurant_id, and amount as parameters.
-- Deduct the amount from the customer's wallet_balance in a customers table and insert a newrecord into the orders table.
-- Use a transaction block: if the customer's wallet_balance is insufficient, ROLLBACK everything; otherwise COMMIT.
ALTER TABLE orders
ADD COLUMN customer_id INT;
CREATE TABLE customers (
    customer_id INT PRIMARY KEY AUTO_INCREMENT,
    customer_name VARCHAR(50) NOT NULL,
    wallet_balance DECIMAL(10,2) NOT NULL
);
INSERT INTO customers (customer_name, wallet_balance)
VALUES
('Amit Sharma', 1000.00),
('Rahul Verma', 200.00);

DELIMITER //
	CREATE PROCEDURE place_order(IN p_customer_id INT,IN p_restaurant_id INT,IN p_amount INT)
    BEGIN 
		START TRANSACTION ;
			IF(p_amount>(select wallet_balance from customers where customer_id = p_customer_id)) THEN
				ROLLBACK;
			ELSE 
				COMMIT;
			END IF;
		UPDATE customers SET wallet_balance = wallet_balance - p_amount WHERE customer_id = p_customer_id;
        INSERT INTO orders (restaurant_id, customer_name, total_amount, order_date) 
        VALUES
        (p_restaurant_id,(select customer_name FROM customers WHERE customer_id = p_customer_id),p_amount,CURDATE());
	END //
DELIMITER ;

DESC orders;
select * from customers;
-- Test with a valid order and an order exceeding wallet balance. Screenshot both outcomes from MySQL Workbench.