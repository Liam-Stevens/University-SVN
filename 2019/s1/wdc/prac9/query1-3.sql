SELECT first_name, last_name, rental_date FROM rental INNER JOIN customer ORDER BY MAX(return_date-rental_date) ASC LIMIT 1;
