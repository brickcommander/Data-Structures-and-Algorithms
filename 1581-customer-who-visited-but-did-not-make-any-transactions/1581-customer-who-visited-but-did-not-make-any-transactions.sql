SELECT customer_id, COUNT(visit_id) AS count_no_trans FROM 
    (SELECT * FROM Visits WHERE visit_id NOT IN (
            SELECT visit_id FROM Transactions)) T GROUP BY customer_id;