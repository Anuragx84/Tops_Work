-- 1.Create a table called Playlist with columns: id, song_name, artist, genre, and play_count. Insert at least 5 sample records representing your favorite songs from Spotify.
CREATE TABLE Playlist (
    id INT PRIMARY KEY AUTO_INCREMENT,
    song_name VARCHAR(100),
    artist VARCHAR(100),
    genre VARCHAR(50),
    play_count INT
);

INSERT INTO Playlist (song_name, artist, genre, play_count)
VALUES
('Perfect', 'Ed Sheeran', 'Pop', 1200),
('Blinding Lights', 'The Weeknd', 'Synth-pop', 950),
('Kesariya', 'Arijit Singh', 'Bollywood', 1500),
('Shape of You', 'Ed Sheeran', 'Pop', 1800),
('Heeriye', 'Jasleen Royal', 'Indie Pop', 800);

-- 2.Write a SELECT query to display only the song_name and artist from the Playlist table, but show the artist column as 'Singer' using an alias.
SELECT song_name,artist AS 'Singer' FROM Playlist;

-- 3.Write a SELECT query to find all songs in the Playlist table where the genre is 'Pop' and play_count is greater than 100. Sort the results by play_count in descending order.
select song_name from Playlist WHERE genre = 'Pop' AND play_count > 100 ORDER BY play_count DESC;

-- 4.Use the COUNT aggregate function to find out how many songs in your Playlist table belong to the genre 'Hip-Hop'.
SELECT count(*) from Playlist WHERE genre = 'Hip-Hop';

-- 5.Write a SELECT query that shows the total number of plays (SUM of play_count) for each genre in your Playlist table, grouped by genre.<br><br><em><strong>Hint:</strong> Use GROUP BY with the SUM function to aggregate play counts by genre.</em>
SELECT sum(play_count) from Playlist group by genre;
