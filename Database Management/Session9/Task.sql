-- 1.Create a SQL script to insert a new order into an Orders table, then use COMMIT to save the transaction and verify that the new order persists after reconnecting to the database.
START TRANSACTION;
INSERT INTO Orders (order_id, order_total)
VALUES (101, 1500.00);
COMMIT;

-- 2.Simulate a Zomato-style food order process: insert two new items into an OrderItems table, then use ROLLBACK to undo the changes before committing. Check that no new items remain in the table after rollback.
START TRANSACTION;
INSERT INTO OrderItems (item_id, item_name)
VALUES (101, 'Pizza');
INSERT INTO OrderItems (item_id, item_name)
VALUES (102, 'Burger');
ROLLBACK;
SELECT *
FROM OrderItems
WHERE item_id IN (101, 102);


-- 3.In a Flipkart-like shopping cart scenario, use SAVEPOINT to mark a point after adding a product to the Cart table, add another product, then use ROLLBACK TO SAVEPOINT to undo only the last addition. Show the final contents of the Cart table.
START TRANSACTION;
INSERT INTO Cart (product_id, product_name) VALUES (1, 'Laptop');
SAVEPOINT sp1;
INSERT INTO Cart (product_id, product_name) VALUES (2, 'Headphones');
ROLLBACK TO SAVEPOINT sp1;
SELECT * FROM Cart;
COMMIT;

-- 4.Write a trigger on a Wallet table that automatically deducts the purchase amount from the user's balance whenever a new transaction is inserted, similar to how Paytm updates wallet balance after a payment.
CREATE TABLE Wallet (
    user_id INT PRIMARY KEY,
    balance DECIMAL(10,2)
);

CREATE TABLE WalletTransactions (
    transaction_id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    amount DECIMAL(10,2),
    FOREIGN KEY (user_id) REFERENCES Wallet(user_id)
);
DELIMITER //

CREATE TRIGGER deduct_wallet_balance
AFTER INSERT ON WalletTransactions
FOR EACH ROW
BEGIN
    UPDATE Wallet
    SET balance = balance - NEW.amount
    WHERE user_id = NEW.user_id;
END //

DELIMITER ;
INSERT INTO Wallet (user_id, balance)
VALUES (1, 5000.00);
INSERT INTO WalletTransactions (user_id, amount)
VALUES (1, 1200.00);
SELECT * FROM Wallet;

-- 5.Use ChatGPT to generate a SQL test scenario where a trigger incorrectly updates a user's balance after an expense entry. Paste the scenario and your corrected trigger code, explaining how you fixed the error.<br><br><em><strong>Hint:</strong> Ask ChatGPT for a buggy trigger example and a test case that exposes the bug.</em>
DELIMITER //

CREATE TRIGGER buggy_balance_update
AFTER INSERT ON Expenses
FOR EACH ROW
BEGIN
    UPDATE Wallet
    SET balance = balance + NEW.amount
    WHERE user_id = NEW.user_id;
END //

DELIMITER ;
INSERT INTO Wallet (user_id, balance)
VALUES (1, 5000);
INSERT INTO Expenses (user_id, amount)
VALUES (1, 1000);
SELECT * FROM Wallet
WHERE user_id = 1;
DROP TRIGGER buggy_balance_update;
DELIMITER //

CREATE TRIGGER correct_balance_update
AFTER INSERT ON Expenses
FOR EACH ROW
BEGIN
    UPDATE Wallet
    SET balance = balance - NEW.amount
    WHERE user_id = NEW.user_id;
END //

DELIMITER ;