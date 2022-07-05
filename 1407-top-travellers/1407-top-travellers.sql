select name, if(distance IS NULL, 0, sum(distance)) travelled_distance from (
    Users LEFT JOIN Rides ON (Users.id = Rides.user_id)
) GROUP BY user_id ORDER BY sum(distance) DESC, name ASC;