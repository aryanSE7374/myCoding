SHOW DATABASES;
USE temp;
SHOW TABLES;
USE student;
/* ------------------------------------------------------------------------------------ */

 -- JOINS
 SELECT * FROM customers;
 SELECT * FROM orders;
 -- INNER JOIN
 
SELECT c.*, O.* FROM customers AS c INNER JOIN orders as o ON c.id = o.cust_id;

-- OUTER JOIN
INSERT INTO customers VALUES (4, 'Yuusf');

-- LEFT JOIN
SELECT c.*, O.* FROM customers AS c LEFT JOIN orders as o ON c.id = o.cust_id;

-- RIGHT JOIN
SELECT c.*, O.* FROM customers AS c RIGHT JOIN orders as o ON c.id = o.cust_id;

-- FULL JOIN => NOTE THERE"S NO FULL JOIN KEYWORD IN MysQL
-- so we emulate

SELECT * FROM 
customers AS c LEFT JOIN orders as o ON c.id = o.cust_id 
UNION
SELECT * FROM customers AS c RIGHT JOIN orders as o ON c.id = o.cust_id;


-- CROSS JOIN = CARTESIAN PRODUCT (rarely used in practical purposes )
SELECT * FROM customers CROSS JOIN orders;

-- SELF JOIN (emulated using INNER JOIN)
SELECT * FROM customers as c1 INNER JOIN customers as c2 ON c1.id = c2.id; 
SELECT * FROM orders as o1 INNER JOIN orders as o2 ON o1.order_id = o2.order_id;

/* ------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------ */

-- PRACTICE ques : using temp database
SHOW TABLES;

-- =========================
-- CREATE EMPLOYEE TABLE
-- =========================

CREATE TABLE employee (
    id INT PRIMARY KEY,
    fname VARCHAR(50),
    lname VARCHAR(50),
    age INT,
    emailID VARCHAR(100),
    phoneNo VARCHAR(20),
    city VARCHAR(50)
);

-- =========================
-- CREATE PROJECT TABLE
-- empID references employee(id)
-- clientID references client(id)
-- =========================

CREATE TABLE project (
    id INT PRIMARY KEY,
    empID INT,
    name VARCHAR(50),
    startdate DATE,
    clientID INT,
    FOREIGN KEY (empID) REFERENCES employee(id)
);

-- =========================
-- CREATE CLIENT TABLE
-- empID references employee(id)
-- =========================

CREATE TABLE client (
    id INT PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    age INT,
    emailID VARCHAR(100),
    phoneNo VARCHAR(20),
    city VARCHAR(50),
    empID INT,
	FOREIGN KEY (empID) REFERENCES employee(id)
);

-- =========================
-- NOW ADD FOREIGN KEY
-- project.clientID -> client(id)
-- =========================

ALTER TABLE project
ADD CONSTRAINT fk_project_client
FOREIGN KEY (clientID)
REFERENCES client(id);

-- =========================
-- INSERT INTO EMPLOYEE
-- =========================

INSERT INTO employee
(id, fname, lname, age, emailID, phoneNo, city)
VALUES
(1, 'Aman', 'Proto', 32, 'aman@gmail.com', '898', 'Delhi'),
(2, 'Yagya', 'Narayan', 44, 'yagya@gmail.com', '222', 'Palam'),
(3, 'Rahul', 'BD', 22, 'rahul@gmail.com', '444', 'Kolkata'),
(4, 'Jatin', 'Hermit', 31, 'jatin@gmail.com', '666', 'Raipur'),
(5, 'PK', 'Pandey', 21, 'pk@gmail.com', '555', 'Jaipur');

-- =========================
-- INSERT INTO CLIENT
-- =========================

INSERT INTO client
(id, first_name, last_name, age, emailID, phoneNo, city, empID)
VALUES
(1, 'Mac', 'Rogers', 47, 'mac@hotmail.com', '333', 'Kolkata', 3),
(2, 'Max', 'Poirier', 27, 'max@gmail.com', '222', 'Kolkata', 3),
(3, 'Peter', 'Jain', 24, 'peter@abc.com', '111', 'Delhi', 1),
(4, 'Sushant', 'Aggarwal', 23, 'sushant@yahoo.com', '45454', 'Hyderabad', 5),
(5, 'Pratap', 'Singh', 36, 'p@xyz.com', '77767', 'Mumbai', 2);

-- =========================
-- INSERT INTO PROJECT
-- =========================

INSERT INTO project
(id, empID, name, startdate, clientID)
VALUES
(1, 1, 'A', '2021-04-21', 3),
(2, 2, 'B', '2021-03-12', 1),
(3, 3, 'C', '2021-01-16', 5),
(4, 3, 'D', '2021-04-27', 2),
(5, 5, 'E', '2021-05-01', 4);

-- =========================
SELECT * FROM employee;
SELECT * FROM client;
SELECT * FROM project;
-- =========================

/* ------------------------------------------------------------------------------------ */

-- INNER JOIN
-- Enlist all the employees ID’s, names along with the Project allocated to them.
SELECT e.id, e.fname, e.lname, p.id, p.name 
FROM employee as e 
INNER JOIN project as p
ON e.id = p.empID;

-- JOINN without using JOIN keyword
SELECT e.id, e.fname, e.lname, p.id, p.name 
FROM employee as e, project as p
WHERE e.id = p.empID;

-- Fetch out all the employee ID’s and their contact detail who have been working
-- from Jaipur with the clients name working in Hyderabad.

/*
-- query try1 
SELECT e.id, e.emailID, e.phoneNo, c.id, c.first_name, c.last_name
FROM employee as e 
INNER JOIN client as c
ON e.city = 'Jaipur' AND c.city = 'Hyderabad';

-- This query is WRONG as it is a filtered cartesian product
-- Suppose:
-- 3 Jaipur employees + 2 Hyderabad clients
-- Then query 1 produces: 3 × 2 = 6 rows , even if employees and clients are unrelated

*/

-- correct query
SELECT e.id, e.emailID, e.phoneNo, c.id, c.first_name, c.last_name
FROM employee as e 
INNER JOIN client as c
ON e.id = c.empID WHERE e.city = 'Jaipur' AND c.city = 'Hyderabad';

-- LEFT JOIN
-- Fetch out each project allocated to each employee.

SELECT e.id as empID, e.fname, e.lname, p.id as projID, p.name 
FROM employee as e
LEFT JOIN project as p 
ON e.id = p.empId;

-- RIGHT JOIN
-- List out all the projects along with the employee’s name and their respective allocated email ID.

-- using LEFT JOIN
SELECT p.id, p.name, e.fname, e.lname, e.emailID
FROM project as p
LEFT JOIN employee as e
on p.empID = e.id;

-- using RIGHT JOIN
SELECT p.id, p.name, e.fname, e.lname, e.emailID
FROM employee as e
RIGHT JOIN project as p
on e.id = p.empID;


-- CROSS JOIN 
-- List out all the projects along with the employee's name and their respective allocated email ID

SELECT e.fname, e.lname, p.id, p.name
FROM employee as e
CROSS JOIN project as p;

/* ------------------------------------------------------------------------------------ */

-- using Joins without using JOIN keyword
-- syntax : SELECT * FROM left, right WHERE left.id = right.id;
-- example in INNER JOIN section

/* ------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------ */

-- SET OPERATIONS

-- CREATE TABLES

CREATE TABLE dept1 (
	empid INT PRIMARY KEY,
	name VARCHAR(40),
	role VARCHAR(20)
);

CREATE TABLE dept2 (
	empid INT PRIMARY KEY,
	name VARCHAR(40),
	role VARCHAR(20)
);

INSERT INTO dept1 VALUES 
(1, 'A', 'engineer'),
(2, 'B', 'salesman'),
(3, 'C', 'manager'),
(4, 'D', 'salesman'),
(5, 'E', 'engineer');

INSERT INTO dept2 VALUES 
(3, 'C', 'manager'),
(6, 'F', 'marketing'),
(7, 'G', 'salesman');


-- UNION
SELECT * FROM dept1
UNION
SELECT * FROM dept2;


-- INTERSECTION syntax 1
SELECT DISTINCT empid, dept1.name, dept1.role FROM 
dept1 INNER JOIN dept2 USING(empid);

-- INTERSECTION syntax 2
SELECT DISTINCT dept1.empid, dept1.name, dept1.role FROM 
dept1 INNER JOIN dept2 ON dept1.empid = dept2.empid;

-- INTERSECT keyword syntax (research about it)
-- similaryly we have a EXCEPT keyword for minus in Oracle
/*
SELECT * FROM dept1 
INTERSECT 
SELECT * FROM dept2;
*/

-- MINUS syntax 1
/*
NOTE : 
USING(empid) automatically means: dept1.empid = dept2.empid
*/
SELECT empid, dept1.name, dept1.role FROM dept1 LEFT JOIN dept2
USING(empid) WHERE dept2.empid IS NULL;

-- MINUS syntax 2
SELECT dept1.empid, dept1.name, dept1.role FROM dept1 LEFT JOIN dept2
ON dept1.empid = dept2.empid WHERE dept2.empid IS NULL;

/* ------------------------------------------------------------------------------------ */

-- PRACTICE QUESTIONS
-- List out all the employees in the company
SELECT * FROM dept1
UNION
SELECT * FROM dept2;

-- list out all the employees in all departments who work as salesman
SELECT * FROM dept1 WHERE role = 'salesman'
UNION
SELECT * FROM dept2 WHERE role = 'salesman';

-- list out all the employees who work in both the departments.
SELECT dept1.* FROM dept1 INNER JOIN dept2 USING(empid);


-- List out all the employees working in dept1 but not in dept2.
SELECT dept1.* FROM dept1 LEFT JOIN dept2 USING(empid) WHERE dept2.empid IS NULL;

/* ------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------ */

-- Sub-Queries (alternative method to joins)
-- a.k.a nested queries

-- SUB QUERIES
-- WHERE clause same table
-- employees with age > 30
SELECT * FROM employee WHERE age IN (SELECT age FROM employee WHERE age > 30);


-- WHERE clause different table
-- emp details working in more than 1 project.
SELECT * FROM employee WHERE id IN (
    SELECT empID FROM project GROUP BY empID HAVING COUNT(empID) > 1
);


-- single value subquery
-- emp details having age > avg(age)
SELECT * FROM Employee WHERE age > (SELECT AVG(age) FROM Employee);


-- FROM clause
-- select max age person whose first name contains 'a'
SELECT MAX(age) FROM (SELECT * FROM Employee WHERE fname LIKE '%a%') AS temp;


-- Corelated subquery
-- find 3rd oldest employee
SELECT *
FROM Employee e1
WHERE 3 = (
    SELECT COUNT(e2.age)
    FROM Employee e2
    WHERE e2.age >= e1.age
);

/* ------------------------------------------------------------------------------------ */
/* ------------------------------------------------------------------------------------ */

-- MySQL Views
SELECT * FROM employee;

-- creating a view
CREATE VIEW custom_view AS SELECT fname, age FROM employee;
-- using view
SELECT * FROM custom_view;

-- altering view
ALTER VIEW custom_view AS SELECT fname, lname, age FROM employee;

-- DROPPING VIEW
DROP VIEW IF EXISTS custom_view;

/* ------------------------------------------------------------------------------------ */
/*
NOTE : 
*/



