#GROUP #7
#DARIUS AYVAZIAN

#Midterm 2
#-----------------------------------------
#Q1
SELECT CONCAT_WS(u_first, u_last) as 'name', 
(SELECT COUNT(s_active) FROM Subscriptions S WHERE S.u_id = U.u_id) as 'Subscriptions', 
(SELECT SUM(s_price) FROM Services WHERE s_id IN (SELECT s_id FROM Subscriptions S WHERE s_active > 0 AND S.u_id = U.u_id)) as 'Expenses'
FROM Users U;

#Q2
DELETE FROM Subscriptions
WHERE u_id IN (SELECT u_id FROM Users WHERE email LIKE '%@notabot.net' OR concat_ws(u_first, u_last) = 'NOTA BOT');

DELETE FROM USERS
WHERE email LIKE '%@notabot.net' OR concat_ws(u_first, u_last) = 'NOTA BOT';

#Q3
SELECT s_name AS 'Name', s_price AS 'Price', Subs, Subs*s_price AS 'Revenue'
FROM Services S LEFT JOIN (SELECT COUNT(s_active) as Subs FROM Subscriptions GROUP BY s_id) Sb
ON S.s_id = Sb.s_id; 

#Q4
Update Subscriptions
SET s_active =1
WHERE s_active =0 AND u_id IN (SELECT u_id FROM Users WHERE email like '%@gmail.com')
AND s_id IN (SELECT s_id FROM Services WHERE s_name = 'Apple Music');
