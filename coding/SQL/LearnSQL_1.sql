SHOW DATABASES;


/* ------------------------------------------------------------------------------------ */
-- table to practice sorting

CREATE DATABASE temp;

USE temp;

CREATE TABLE worker (
    WORKER_ID INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    FIRST_NAME VARCHAR(25),
    LAST_NAME VARCHAR(25),
    SALARY INT,
    JOINING_DATE DATETIME,
    DEPARTMENT VARCHAR(25)
);

DROP TABLE worker;
DESC worker;

INSERT INTO worker
(WORKER_ID, FIRST_NAME, LAST_NAME, SALARY, JOINING_DATE, DEPARTMENT)
VALUES
(1, 'Monika',   'Arora',   100000, '2014-02-20 09:00:00', 'HR'),
(2, 'Niharika', 'Verma',    80000, '2014-06-11 09:00:00', 'Admin'),
(3, 'Vishal',   'Singhal', 300000, '2014-02-20 09:00:00', 'HR'),
(4, 'Amitabh',  'Singh',   500000, '2014-02-20 09:00:00', 'Admin'),
(5, 'Vivek',    'Bhati',   500000, '2014-06-11 09:00:00', 'Admin'),
(6, 'Vipul',    'Diwan',   200000, '2014-06-11 09:00:00', 'Account'),
(7, 'Satish',   'Kumar',    75000, '2014-01-20 09:00:00', 'Account'),
(8, 'Geetika',  'Chauhan',  90000, '2014-04-11 09:00:00', 'Admin');
    
    
SELECT * FROM worker;

/* ------------------------------------------------------------------------------------ */

CREATE DATABASE STUDENT;
USE STUDENT;
SHOW TABLES;

/* create a table */

CREATE TABLE students (
	roll INT PRIMARY KEY , 
    name VARCHAR(50),
    age INT NOT NULL
);

SHOW TABLES;

DESC students;

SELECT * FROM students;

/*.Add values to the table */

INSERT INTO students VALUES(1 , 'Aryan' , 20);
INSERT INTO students VALUES(2 , 'Kanak' , 21);
INSERT INTO students VALUES(3 , 'Yusuf' , 22);


/* ------------------------------------------------------------------------------------ */

-- CONSTRAINTS IN DDL

--  CREATING ANOTHER TABLE using constraints

-- 1. primary key = unique + not null, 2. unique, 3. not null, 4. default

CREATE TABLE employees (
	emp_id INT PRIMARY KEY,
	name VARCHAR(30) NOT NULL,
	email VARCHAR(100) UNIQUE,
	balance INT DEFAULT 0
);

-- to use composite primary key :- use PRIMARY KEY (arg1, arg2, ...) 

DESC employees;

-- multiple insert syntax
-- INSERT INTO table (arg1, arg2, ...) VALUES (tup1), , (tup2), ... ;

INSERT INTO employees ( emp_id, name, email ) VALUES
(1, 'Aryan', 'aryan@gmail.com'), (2, 'Vishal', 'vishal@gmail.com') ;

-- erase all data

TRUNCATE employees;

-- method 2 : have to provide all the attributes that too in order they are created
INSERT INTO employees VALUES (1, 'Aryan', 'aryan@gmail.com', 0), (2, 'Vishal', 'vishal@gmail.com', 0) ;

SELECT * FROM employees;


--  CREATING ONE MORE VERSION OF employees TABLE

CREATE TABLE employees (
	emp_id INT PRIMARY KEY,
	name VARCHAR(30) NOT NULL,
	email VARCHAR(100) UNIQUE,
	balance INT DEFAULT 0
);


-- using 5. check constraint

CREATE TABLE employees2 (
	emp_id INT PRIMARY KEY,
	name VARCHAR(30),
	age INT CHECK (age >= 18)
);

INSERT INTO employees2 values (1,'a',20);
INSERT INTO employees2 values (2,'b',18);
INSERT INTO employees2 values (3,'c',14); -- invalid insert

SELECT * FROM employees2;

DROP TABLE employees2;

-- can also used NAMED CONSTRAINT using :- CONSTRAINT age_check CHECK (age >= 18)

CREATE TABLE employees2 (
	emp_id INT PRIMARY KEY,
	name VARCHAR(30),
	age INT,
	CONSTRAINT age_check CHECK (age >= 18)
);


-- 6. FOREIGN KEY EXAMPLE :- parent table : customers, child table : oders

-- referential integrity : FK maintains consistency between related tables

CREATE TABLE customers (
	id INT PRIMARY KEY,
	name VARCHAR(100)
);


/*
here, 
	Database ensures: 
		orders.cust_id must exist inside customers.id 
		that is the if id used in child table must exist in the parent table
*/

CREATE TABLE orders (
	order_id INT PRIMARY KEY, 
    amount INT,
    cust_id INT,
    FOREIGN KEY (cust_id) REFERENCES customers(id)
);


INSERT INTO customers VALUES (1, 'Aryan'), (2, 'Laxmi'), (3, 'Krishna');

SELECT * FROM customers;

INSERT INTO orders VALUES (101, 500, 1), (102, 200, 1), (103, 100, 2), (104, 1000, 3);

SELECT * FROM orders;

/* ------------------------------------------------------------------------------------ */

-- DATA RETREIVAL LANGUAGE : SELECT <set of columns> FROM <table>

/*
NOTE : order of ecxecution : from RIGHT to LEFT
can we use SELECT keyword without using FROM clause? ans : YES, using DUAL tables
*/

SELECT 12+12;

SELECT now();

SELECT * FROM customers WHERE name LIKE '_r%';

-- sorting using ORDER BY

SELECT * FROM employees ORDER BY name;

SELECT * FROM worker;
SELECT * FROM worker ORDER BY salary; -- ASC (default) / DESC


-- distinct values using DISTINCT kerword
/*
NOTE : use DISTINCT only when aggregation functions not required
*/

SELECT DISTINCT department FROM worker;

-- grouping of data using GROUP BY clause
	
-- grouping is used for aggregation associated with aggregation functions : {COUNT, SUM, AVG, MIN, MAX}

SELECT department FROM worker GROUP BY department; 
-- NOTE : grouping not needed since no aggregation function used (sql compiler may internally treat it as DISTINCT for optimization)

SELECT COUNT(DISTINCT department) FROM worker; -- aggregation on DISTINCT keyword

-- Ques : find num of employees working in different departments
SELECT department, COUNT(*) FROM worker GROUP BY department;

-- Ques : find avg salary per department
SELECT AVG(salary) FROM worker; -- this gives overall avg salary of all the workers
SELECT department, AVG(salary) FROM worker GROUP BY department; -- but this uses aggregation on groups and hence gives avg per department

-- min salary per department
SELECT department, MIN(salary) FROM worker GROUP BY department;

-- max salary per department
SELECT department, MAX(salary) FROM worker GROUP BY department;

-- total salary per department
SELECT department, SUM(salary) FROM worker GROUP BY department;

SELECT * FROM worker;

-- GROUP BY using composite attribute
-- SELECT c1, c2, c3 FROM sample_table WHERE cond GROUP BY c1, c2, c3.
-- it create groups where c1, c2, c3 all are identical [similar to composite keys]
-- if even one column differs -> new group
-- this query is equivalent to : SELECT DISTINCT c1, c2, c3 FROM worker;

SELECT worker_id, salary, department FROM worker GROUP BY worker_id, salary, department; -- practically no impact as id is always going to be unique
SELECT salary, department FROM worker GROUP BY salary, department; -- groups where salary, department are both identical
SELECT DISTINCT salary, department FROM worker; -- effectively eqivalent to the above query


-- HAVING CLAUSE
/*
used with GROUP BY, similar to WHERE with SELECT
*/

-- Ques : department, count having ,more than 2 workers
SELECT department, COUNT(department) FROM worker GROUP BY department HAVING COUNT(department) > 2;

/* ------------------------------------------------------------------------------------ */

-- ALTER OPERATIONS IN DDL 

SELECT * FROM customers;
SELECT * FROM orders;
SELECT * FROM employees;
SELECT * FROM students;

SELECT * FROM employees2;

/*
employees2 creation
CREATE TABLE employees2 (
	emp_id INT PRIMARY KEY,
	name VARCHAR(30),
	age INT CHECK (age >= 18)
);
*/

DESC employees2;

-- ADD NEW COLUMN
ALTER TABLE employees2 ADD salary FLOAT NOT NULL DEFAULT 0;

-- MODIFY COLUMN :- TO CHANGE DATATYPES OF AN ATTRIBUTE
ALTER TABLE employees2 MODIFY salary DOUBLE NOT NULL DEFAULT 0;

-- CHNAGE COLUMN :- TO RENAME THE COLUMN
-- syntax : ALTER TABLE <table_name> CHANGE COLUMN <OLD_col_name> <NEW_col_name> DATATYPE CONSTRAINTS; 

ALTER TABLE employees2 CHANGE COLUMN salary wage FLOAT NOT NULL DEFAULT 0;

-- DROP COLUMN
ALTER TABLE employees2 DROP COLUMN wage;

-- RENAME TABLE
-- syntax : ALTER TABLE <table_name> RENAME TO <new-table-name>;
ALTER TABLE employees2 RENAME TO emps;
SELECT * FROM emps;

ALTER TABLE emps RENAME TO employees2;
SELECT * FROM employees2;


/* ------------------------------------------------------------------------------------ */

-- DML : DATA MODIFICATION LANGUAGE

-- INSERT INTO command
-- INSERT INTO <table> (c1, c2, ...) VALUES (v1, v2, ...);

INSERT INTO orders VALUES 
(105, 1250, 1, 'Games'), 
(106, 250, 2, 'Food'), 
(107, 100, 1, 'Vegetables'), 
(108, 500, 2, 'Fruits'), 
(109, 32000, 3, 'Phone');

-- UPDATE
UPDATE orders SET amount = 1250, cust_id = 2 WHERE order_id = 102;

SELECT * FROM orders ORDER BY cust_id;
SELECT * FROM orders;
SELECT * FROM customers;

-- ADD NEW COLUMN to orders
ALTER TABLE orders ADD item_name VARCHAR(30);

-- toggle safe moe 0 :- disbale, 1 :- enable
SET SQL_SAFE_UPDATES = 1;

UPDATE orders SET item_name = 'Clothes';

-- DELETE FROM

DELETE FROM orders WHERE order_id = 103; -- works without safe mode only when order_id is a PK

DELETE FROM orders; -- without where will delete all the tuples form the orders table

-- REFERENTIAL INTEGRITY CONSTRAINTS :

DELETE FROM customers WHERE id = 2; -- error : due to foreign key constraints

-- SOLUTIONS: 
-- 1. ON DELETE CASCASE : will delete the child table's rows wherever the parent was present
-- 2. ON DELETE SET NULL : will set FK value null to NULL instead of deleting the entire row

/* ---------------------------- */

DROP TABLE customers;
DROP TABLE orders;

CREATE TABLE customers (
	id INT PRIMARY KEY,
	name VARCHAR(100)
);

INSERT INTO customers VALUES (1, 'Aryan'), (2, 'Laxmi'), (3, 'Krishna');
INSERT INTO customers VALUES (2, 'Laxmi');


/* ------------------------------ */

CREATE TABLE orders (
    order_id INT PRIMARY KEY,
    amount INT,
    cust_id INT,
    item_name VARCHAR(50),
    -- FOREIGN KEY (cust_id) REFERENCES customers(id) ON DELETE CASCADE
    FOREIGN KEY (cust_id) REFERENCES customers(id) ON DELETE SET NULL
);

INSERT INTO orders (order_id, amount, cust_id, item_name) VALUES
(101, 500, 1, 'Clothes'),
(103, 1000, 2, 'Clothes'),
(104, 1000, 3, 'Clothes'),
(105, 1250, 1, 'Games'),
(106, 250, 2, 'Food'),
(107, 100, 1, 'Vegetables'),
(108, 500, 2, 'Fruits'),
(109, 32000, 3, 'Phone');




-- REPLACE INTO command
SELECT * FROM orders;

-- syntax #1
REPLACE INTO orders (order_id, amount) VALUES (110, 100); -- adds new row with given values , rest columns will be NULL
REPLACE INTO orders (order_id, cust_id) VALUES (108, 3); -- updates existing tuple with order_id = 108, rest columns NU LL 

-- another syntax #2
REPLACE INTO orders SET order_id = 111, cust_id = 1; -- if order_id exists then updates else inserts

-- syntax #3
REPLACE INTO orders(order_id, cust_id) SELECT order_id, cust_id FROM orders WHERE order_id = 111; -- will keep only the passed column values, rest will be set to NULL

/* ------------------------------------------------------------------------------------ */

/*
NOTE : 
*/

