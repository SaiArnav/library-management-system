# 📚 LIBRARY MANAGEMENT SYSTEM

## Project Overview

A menu-driven console application developed in C using Data Structures for efficient library operations. The system manages books, members, book issue/return records, fine calculation, searching, reporting, and recommendation features.

---

## Team Members

| Role                                     | Name              |
| ---------------------------------------- | ----------------- |
| Core Library & AI recommendation         |  Arnav            |
| Book, Member & Search                    | Govardhan         |
| Issue, Fine & Reports                    | Shrejal           |
| Documentation                            | Bhavya            |
| Output Management & tester               | Ganesh            |

---
## Folder Structure

```
library-management-system/
│
├── src/
├── data/
│   ├── books.dat
│   ├── members.dat
│   └── issued.dat
│
├── outputs/
├── docs/
│   
└── README.md
```
---

## Main Menu

```
========== LIBRARY MANAGEMENT SYSTEM ==========
1. Add Book
2. Update Book
3. Delete Book
4. Register Member
5. Update Member
6. Delete Member
7. Issue Book
8. Return Book
9. Search Book by Title
10. Search Book by Author
11. Search Book by Genre
12. List Issued Books
13. Generate Overdue Report
14. AI Book Suggestions
15. Display All Books
16. Display All Members
17. Exit
===============================================
Enter your choice:
```

---

## Features

### 1. Add Book

```
Enter Book ID: 101
Enter Title: Data Structures
Enter Author: Mark Allen
Enter Genre: Computer Science

Book added successfully.
```

### 2. Update Book

```
Enter Book ID to update: 101

New Title: Advanced Data Structures
Book updated successfully.
```

### 3. Delete Book

```
Enter Book ID: 101

Book deleted successfully.
```

### 4. Register Member

```
Enter Member ID: M001
Enter Member Name: Bhavya

Member registered successfully.
```

### 5. Update Member

```
Enter Member ID: M001

New Name: Bhavya Sri

Member updated successfully.
```

### 6. Delete Member

```
Enter Member ID: M001

Member deleted successfully.
```

### 7. Issue Book

```
Enter Book ID: 102
Enter Member ID: M001

Issue Date : 01-05-2026
Due Date   : 15-05-2026

Book issued successfully.
```

### 8. Return Book

```
Enter Book ID: 102

Return Date : 20-05-2026

Overdue Days : 5
Fine         : ₹10

Book returned successfully.
```

### 9. Search by Title

```
Enter Title Keyword: Data

Matching Books:
101  Data Structures
102  Advanced Data Structures
```

### 10. Search by Author

```
Enter Author Name: Mark Allen

Matching Books:
101 Data Structures
```

### 11. Search by Genre

```
Enter Genre: Computer Science

Matching Books:
101 Data Structures
102 Algorithms
```

### 12. List Issued Books

```
Issued Books

Book ID   Member ID   Due Date
--------------------------------
102       M001        15-05-2026
105       M003        18-05-2026
```

### 13. Overdue Report

```
Overdue Books

Book ID   Member ID   Days Late   Fine
---------------------------------------
102       M001           5         ₹10
105       M003           3         ₹6
```

### 14. AI Suggestions

```
Based on previous borrowing history:

Recommended Books:
1. Operating Systems
2. Computer Networks
3. Database Management Systems
```

### 15. Display All Books

```
Book ID   Title                 Author
-----------------------------------------
101       Data Structures       Mark Allen
102       Algorithms            Thomas
103       DBMS                  Korth
```

### 16. Display All Members

```
Member ID   Name
-----------------------
M001        Bhavya Sri
M002        Govardhan
M003        Ganesh
```

### 17. Exit

```
Thank You for Using Library Management System
```

---

## Fine Calculation

```
Fine = Overdue Days × ₹2
```

Example:

```
Days Late = 5
Fine = 5 × 2 = ₹10
```

---

## Output

```
Library Management System executed successfully.
Books, Members, Issue/Return records, Searching,
Reports and AI Suggestions are managed through
a menu-driven console interface.
```
