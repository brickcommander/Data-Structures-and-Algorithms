-- DELETE P1 FROM Person AS P1, Person AS P2
-- WHERE P1.id > P2.id AND P1.email = P2.email;



-- OR Another Query


DELETE FROM Person WHERE id NOT IN (
    SELECT Temp.id FROM (
        SELECT MIN(id) AS id FROM Person GROUP BY email
    ) AS Temp
);