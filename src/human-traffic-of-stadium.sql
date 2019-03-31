-- http://leetcode.com/problems/human-traffic-of-stadium/description/
SELECT t.* FROM stadium t
    LEFT JOIN stadium m1 ON t.id - 1 = m1.id
    LEFT JOIN stadium m2 ON t.id - 2 = m2.id
    LEFT JOIN stadium p1 ON t.id + 1 = p1.id
    LEFT JOIN stadium p2 ON t.id + 2 = p2.id
WHERE (t.people >= 100 AND m1.people >= 100 AND m2.people >= 100)
     OR (t.people >= 100 AND p1.people >= 100 AND p2.people >= 100)
     OR (t.people >= 100 AND p1.people >= 100 AND m1.people >= 100)
ORDER BY id;
