-- 1.Write a PL/SQL block that declares two variables: one for a user's name (VARCHAR2) and one for their age (NUMBER). Assign values and print both using DBMS_OUTPUT.PUT_LINE.
SET @user_name = 'RAHUL';
SET @age = 25;

SELECT @user_name AS Name, @age AS Age;

-- 2.Create a PL/SQL block that uses an IF statement to check if a given order amount is above 500. If yes, print 'Eligible for free delivery', else print 'Delivery charges apply'.
DELIMITER //

CREATE PROCEDURE cehck()
BEGIN
DECLARE order_amount DECIMAL(10,2) DEFAULT 600;
if order_amount>500 Then
	select 'ELIGIBLE FOR DELIVERY' AS message;
ELSE
	select 'DELIVERY CHARGER Apply' AS message;
END IF;
END//

DELIMITER ;
call cehck();

-- 3.Write a PL/SQL block that uses a simple LOOP to print the numbers 1 to 5 using DBMS_OUTPUT.PUT_LINE.<br><br><em><strong>Hint:</strong> Use a counter variable and EXIT WHEN condition inside the loop.</em>
DELIMITER //

CREATE PROCEDURE print_numbers()
BEGIN
DECLARE counter INT DEFAULT 1;
    number_loop: LOOP
        SELECT counter AS number;
        IF counter = 5 THEN
            LEAVE number_loop;
        END IF;
        SET counter = counter + 1;
    END LOOP number_loop;
END //

DELIMITER ;

CALL print_numbers();

-- 4.Declare a cursor in PL/SQL to select all product names from a table called PRODUCTS. Fetch each product name and print it using DBMS_OUTPUT.PUT_LINE.<br><br><em><strong>Hint:</strong> Assume the PRODUCTS table has a column PRODUCT_NAME.</em>
DELIMITER //

CREATE PROCEDURE ShowProducts()
BEGIN
    DECLARE done INT DEFAULT 0;
    DECLARE p_name VARCHAR(100);

    DECLARE product_cursor CURSOR FOR
        SELECT PRODUCT_NAME FROM PRODUCTS;

    DECLARE CONTINUE HANDLER FOR NOT FOUND
        SET done = 1;

    OPEN product_cursor;

    product_loop: LOOP
        FETCH product_cursor INTO p_name;

        IF done = 1 THEN
            LEAVE product_loop;
        END IF;

        SELECT p_name AS PRODUCT_NAME;
    END LOOP;

    CLOSE product_cursor;
END //

DELIMITER ;

CALL ShowProducts();

-- 5.Write a PL/SQL block that tries to divide two numbers entered as variables. If a division by zero occurs, catch the exception and print 'Cannot divide by zero'. Otherwise, print the result.
DELIMITER //

CREATE PROCEDURE divide_numbers()
BEGIN
    DECLARE num1 DECIMAL(10,2) DEFAULT 10;
    DECLARE num2 DECIMAL(10,2) DEFAULT 0;
    IF num2 = 0 THEN
        SELECT 'Cannot divide by zero' AS message;
    ELSE
        SELECT num1 / num2 AS division_result;
    END IF;
END //
DELIMITER ;
CALL divide_numbers();