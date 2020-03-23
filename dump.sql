PRAGMA foreign_keys=ON;
BEGIN TRANSACTION;

CREATE TABLE customers
(
customerID INTEGER PRIMARY KEY AUTOINCREMENT,
name varchar(50) UNIQUE,
address varchar(90),
website varchar(50),
interestLevel varchar(50),
doNotContact bool,
keyAccount bool,
pamphletSent bool
);
INSERT INTO customers VALUES(1,'Orange County Airport','18601 Airport Way Santa Ana, CA 92707','oc.airport.gov','Very Interested',0,1,0);
INSERT INTO customers VALUES(2,'Los Angeles Airport','1 World Way, Los Angeles, CA 90045','lax.airport.gov','Very Interested',0,1,0);
INSERT INTO customers VALUES(3,'FBI','1234 Lincoln Ave., Washington D.C. 00234','www.fbi.gov','Not Interested',0,1,0);
INSERT INTO customers VALUES(4,'CIA','987 Jefferson Blvd Baltimore, MD 00754','www.cia.gov','Somewhat Interested',0,1,0);
INSERT INTO customers VALUES(5,'Los Angeles Dodgers','1000 Elysian Park Avenue, Los Angeles, CA 90012','www.ladodgers.com','Very Interested',0,0,0);
INSERT INTO customers VALUES(6,'Los Angeles Angels of Anaheim','2000 East Gene Autry Way, Anaheim, CA 92806','www.laangels.com','Never Call Again',1,0,0);
INSERT INTO customers VALUES(7,'Amazon','410 Terry Ave. North, Seattle, WA 98109','www.amazon.com','Somewhat Interested',0,0,0);
INSERT INTO customers VALUES(8,'Cisco','170 West Tasman Dr., San Jose, CA 9513','www.cisco.com','Very Interested',0,1,0);
CREATE TABLE items
(
itemID INTEGER PRIMARY KEY AUTOINCREMENT,
name varchar(50),
price float);
INSERT INTO items VALUES(1,'iRobot',300.0);
INSERT INTO items VALUES(2,'Talon',600.0);
INSERT INTO items VALUES(3,'Dragon Runner',900.0);
CREATE TABLE users
(
userID INTEGER PRIMARY KEY AUTOINCREMENT,
name varchar(50),
username varchar(32),
password varchar(32),
admin bool
);
INSERT INTO users VALUES(1,'MEGA QT','admin','admin',1);
CREATE TABLE purchases
(
customerID int,
itemID int,
qtyPurchased int,
date varchar(12),
FOREIGN KEY(customerID) REFERENCES customers(customerID) ON DELETE CASCADE,
FOREIGN KEY(itemID) REFERENCES items(itemID) ON DELETE CASCADE
);

INSERT INTO purchases VALUES(1,1,1,'1/10/2000');
INSERT INTO purchases VALUES(1,2,2,'5/21/2010');
INSERT INTO purchases VALUES(1,1,4,'3/10/2010');
INSERT INTO purchases VALUES(2,1,2,'3/3/2004');
INSERT INTO purchases VALUES(3,2,3,'5/10/2013');
INSERT INTO purchases VALUES(4,3,3,'8/10/2015');
INSERT INTO purchases VALUES(2,1,3,'12/12/2012');
INSERT INTO purchases VALUES(1,2,3,'1/30/2011');
INSERT INTO purchases VALUES(5,3,10,'6/6/2018');
INSERT INTO purchases VALUES(2,1,2,'11/12/2010');
INSERT INTO purchases VALUES(3,3,2,'11/23/2019');
INSERT INTO purchases VALUES(6,1,7,'1/1/2009');
INSERT INTO purchases VALUES(7,2,2,'2/5/2020');
INSERT INTO purchases VALUES(8,1,5,'5/10/2010');
INSERT INTO purchases VALUES(8,3,2,'11/20/2009');
INSERT INTO purchases VALUES(7,3,7,'5/5/2005');

CREATE TABLE reviews
(
reviewID INTEGER PRIMARY KEY AUTOINCREMENT,
customerID int,
reviewText varchar(250),
foreign key(customerID) references customers(customerID)
);

INSERT INTO reviews VALUES(1,3,'These robots are amazing!');
INSERT INTO reviews VALUES(2,4,'Very professional service.');

DELETE FROM sqlite_sequence;
INSERT INTO sqlite_sequence VALUES('customers',8);
INSERT INTO sqlite_sequence VALUES('items',3);
INSERT INTO sqlite_sequence VALUES('users',1);
INSERT INTO sqlite_sequence VALUES('reviews',2);
COMMIT;