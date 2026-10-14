-- 1.Create two tables in SQL: influencers (with influencer_id as PRIMARY KEY and name) and posts (with post_id as PRIMARY KEY, influencer_id as FOREIGN KEY, and caption). Insert at least 3 influencers and 2 posts for each influencer.
Create table influencers ( influencer_id  INT auto_increment PRIMARY KEY, name VARCHAR(50));
CREATE table posts ( post_id INT PRIMARY KEY, influencer_id INT , caption VARCHAR(100),FOREIGN KEY (influencer_id) REFERENCES influencers(influencer_id));

INSERT INTO influencers (name)
VALUES
('Rahul Sharma'),
('Priya Verma'),
('Aman Khan');
INSERT INTO posts (post_id, influencer_id, caption)
VALUES
(1, 1, 'My first post'),
(2, 1, 'Travel diaries'),
(3, 2, 'Fashion trends'),
(4, 2, 'Summer vibes'),
(5, 3, 'Fitness journey'),
(6, 3, 'Daily motivation');

-- 2.Write an SQL query using INNER JOIN to display each post's caption along with the name of the influencer who posted it, based on the tables you created.
select posts.caption,influencers.name FROM influencers 
INNER JOIN posts
on influencers.influencer_id = posts.influencer_id;


-- 3.Write an SQL query using LEFT JOIN to show all influencers and their posts, including influencers who haven't posted anything yet. If an influencer has no posts, display 'No Posts' in the caption column.<br><br><em><strong>Hint:</strong> Use IFNULL or COALESCE to handle NULL values in the result.</em>
select influencers.name, IFNULL(posts.caption, 'No Posts') AS caption from influencers left join posts on influencers.influencer_id = posts.influencer_id;

-- 4.Write an SQL query using RIGHT JOIN to list all posts and the corresponding influencer's name, ensuring that even posts without a matching influencer_id (if any) are shown.
SELECT posts.post_id, posts.caption, influencers.name
FROM influencers
RIGHT JOIN posts
ON influencers.influencer_id = posts.influencer_id;