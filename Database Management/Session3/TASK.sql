-- 1.Create a SQL table called Restaurants with columns: id (INT, auto-increment), name (VARCHAR), cuisine (VARCHAR), rating (DECIMAL), and city (VARCHAR). Insert 5 sample restaurants into the table, each with a different cuisine and rating.
CREATE TABLE Restaurants (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(50),
    cuisine VARCHAR(50),
    rating DECIMAL(2,1),
    city VARCHAR(50)
);
INSERT INTO Restaurants (name, cuisine, rating, city)
VALUES
('Pizza Palace', 'Italian', 4.5, 'Indore'),
('Spice Garden', 'Indian', 4.2, 'Bhopal'),
('Sushi House', 'Japanese', 4.7, 'Mumbai'),
('Dragon Wok', 'Chinese', 4.0, 'Delhi'),
('Taco Fiesta', 'Mexican', 4.3, 'Jaipur');

-- 2.Write a SQL UPDATE statement to change the rating of the restaurant named 'Spice Villa' to 4.7 in the Restaurants table.
UPDATE Restaurants 
SET rating = 4.7 WHERE id = 2;

-- 3.Delete all restaurants from the Restaurants table where the rating is less than 3.5 using a SQL DELETE statement.
DELETE FROM Restaurants 
WHERE rating<3.5 AND ID>0;

-- 4.Use a SELECT query with WHERE and LIMIT to fetch the top 2 restaurants in the city 'Ahmedabad' with a rating above 4.0 from the Restaurants table.<br><br><em><strong>Hint:</strong> Combine WHERE for city and rating, and LIMIT to restrict the number of results.</em>
SELECT *
FROM Restaurants
WHERE city = 'Ahmedabad'
AND rating > 4.0
LIMIT 2;