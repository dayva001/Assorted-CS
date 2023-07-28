-- use inventory;
DROP TABLES IF EXISTS Artists,Genre, Members, Titles, Tracks,SalesPeople,Studios,XrefArtistsMembers;
DROP TABLES IF EXISTS Authors,Publishers,Titles,Title_Authors,Royalties;
DROP TABLES IF EXISTS Products,Customers,Orders,Order_details;
DROP TABLES IF EXISTS Sailors,Reserves,Boats;
DROP TABLES IF EXISTS Products, Warehouses, Inventory;


CREATE TABLE Products (
	p_id INT auto_increment PRIMARY KEY, 
	p_name varchar (50) NOT NULL ,
	category  char(20)  NULL,
	brand varchar(40) NULL ,
	launch_date date NOT NULL
);


CREATE TABLE Warehouses (
	w_id int auto_increment PRIMARY KEY, 
	officephone varchar(16) NULL ,
	state varchar(40) NULL
);

CREATE TABLE Inventory (
	p_id int NOT NULL, 
	w_id  int NOT NULL,
	total  varchar(10) NULL,
	updated date NULL,
    CONSTRAINT inv_key
    UNIQUE(p_id, w_id)
	
);


Insert Into Products Values(1, "PlayStation", 'Console', "Sony", "1995-09-09");
Insert Into Products Values(2, "PlayStation 2", 'Console', "Sony", "2000-10-26");
Insert Into Products Values(3, "Xbox", 'Console', "Microsoft", "2001-11-15");
Insert Into Products Values(4, "Xbox 360", 'Console', "Microsoft", "2005-11-22");
Insert Into Products Values(5, "Nintendo DS", 'Handheld', "Nintendo", "2004-11-21");
Insert Into Products Values(6, "PS Vita", 'Handheld', "Sony", "2012-02-15");


Insert Into Warehouses Values(201, "201-234-3213", "CA");
Insert Into Warehouses Values(202, "201-232-3112", "NY");
Insert Into Warehouses Values(203, "201-234-3002", "OH");

Insert Into Inventory Values(1, 201, 172,"2022-02-01");
Insert Into Inventory Values(4, 201, 13,"2020-10-01");
Insert Into Inventory Values(1, 202, 91,"2022-03-01");
Insert Into Inventory Values(2, 202, 61,"2023-09-01");
Insert Into Inventory Values(3, 203, 43,"2022-03-01");
Insert Into Inventory Values(4, 203, 72,"2022-11-01");
Insert Into Inventory Values(5, 201, 31,"2020-10-01");
 
show tables;

#Midterm 1
#Darius Ayvazian

#Q1
SELECT brand, COUNT(p_id) AS 'Number of Products'
FROM Products
GROUP BY brand;

#Q2
SELECT p_id, p_name
FROM Products
WHERE p_name LIKE '%n%' AND p_name LIKE '%s%';

#Q3
SELECT p_name as 'Products not in stock'
FROM Products P LEFT JOIN Inventory I
ON P.p_id = I.p_id
WHERE total IS NULL OR total =0;

#Q4
SELECT w_id, officephone
FROM Warehouses
WHERE w_id IN (SELECT w_id 
			   FROM Inventory
			   WHERE p_id IN(SELECT p_id
							 FROM Products
                             WHERE category = 'Handheld'));
                             
#Q5
SELECT p_name AS 'Product Name', w_id AS 'Locations'
FROM Products P LEFT JOIN Inventory I
ON P.p_id = I.p_id;

#Q6
SELECT W.w_id AS 'Location', SUM(total) AS 'Inventory Size'
FROM Warehouses W INNER JOIN Inventory I
ON W.w_id = I.w_id
GROUP BY W.w_id;

#Q7
SELECT DISTINCT officephone
FROM Warehouses
WHERE w_id IN (SELECT w_id 
			   FROM Inventory
               WHERE p_id IN (SELECT p_id
							  FROM Products
                              WHERE brand = 'Microsoft'));
                              
#Q8
SELECT w_id
FROM Inventory I INNER JOIN Products P
ON I.p_id = P.p_id
GROUP BY brand, w_id
HAVING brand = 'Sony' AND SUM(Total) = MAX(total);