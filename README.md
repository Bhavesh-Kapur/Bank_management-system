# Bank management system - a system made in C language.

## MySQL integration 
To create a dump of MySQL database

```bash
mysqldump -u root -p BANK > BANK.sql
```
To Import the Database:

```bash
mysql -u root -p BANK < BANK.sql
```

### Note Always import database while working and after a fresh commit and Create A dump whenever changes are made in MySQL Database and then commit 

### Run the makefile file to complile the code after updation 
```bash
make
```
This will auto compile the final file 

If there is need to clean up the build use 
```bash
make clean
```

