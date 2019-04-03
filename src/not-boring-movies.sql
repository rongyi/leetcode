-- http://leetcode.com/problems/not-boring-movies/description/
select id, movie, description, rating
from cinema
where description not like "boring" and id % 2 != 0
order by rating desc;
