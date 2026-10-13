-- 2.Create a new database called InstaClone in MySQL Workbench, then create a table named Users with columns: user_id (INT, primary key), username (VARCHAR), email (VARCHAR), and followers_count (INT).
create database Instaclone;
use Instaclone;
create table Users(user_id INT primary key, username VARCHAR(20), email VARCHAR (50), followers_count INT );

--  3.Insert 3 sample users into the Users table you created, using realistic Instagram-style usernames and follower counts.

INSERT INTO Users (user_id, username, email, followers_count)
VALUES
(1, 'rahul_sharma', 'rahul@gmail.com', 1500),
(2, 'priya_verma', 'priya@gmail.com', 3200),
(3, 'tech_aman', 'aman@gmail.com', 850);

-- 4.Create another table in the InstaClone database called Posts with columns: post_id (INT, primary key), user_id (INT), caption (VARCHAR), and post_date (DATE). Add a foreign key from Posts.user_id to Users.user_id to establish a relationship.
CREATE TABLE Posts (
    post_id INT PRIMARY KEY,
    user_id INT,
    caption VARCHAR(255),
    post_date DATE,
    FOREIGN KEY (user_id) REFERENCES Users(user_id)
);


/*
5.Write a short comparison (3-4 lines each) of MySQL, PostgreSQL, Oracle, and SQLite, focusing on where each one is commonly used (for example: web apps, mobile apps, enterprise systems, etc.).

1. MySQL
MySQL is commonly used in web applications and websites. It is popular for its speed, ease of use, and reliability. It is often used with PHP, Java, and other backend technologies.
2. PostgreSQL
PostgreSQL is an advanced open-source relational database. It is commonly used in complex web applications, data analytics, and systems that require advanced queries and data integrity.
3. Oracle Database
Oracle is a commercial database mainly used in large enterprise systems. Banks, hospitals, and large organizations use it to manage large amounts of critical data with high security and reliability.
4. SQLite
SQLite is a lightweight database that stores data directly in a local file without requiring a separate database server. It is commonly used in mobile apps, desktop applications, and embedded systems.
*/