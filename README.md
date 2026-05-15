# 📚 Library Management System

This is a complete console-based library management system built in C++ with STL for efficient book and member management.

## Project Overview

A menu-driven C++ program managing a library catalogue and member issue records. Books and members are stored using STL containers (unordered_map) for fast in-memory operations. The system supports adding books and members, issuing a book with a due-date timestamp, returning it with automatic overdue-fine calculation (₹2 per day), and printing reports of all overdue borrowings. A rule-based AI recommendation engine suggests similar books upon return.

---

## Team Members:-
```
| Role                             | Name              |
--------------------------------------------------------
| Menu & Logic Developer           | Govardhan & Arnav | 
| STL & Data Structures Logic      | Arnav & Shrejal   |
| Search & Report                  | Bhavya            |
| AI Suggestion Engine Developer   | Ganesh            |
```
---
## Project Structure
```
library_system/
│
├── library.h          # Class declarations & structure definitions
├── library.cpp        # All function implementations
├── main.cpp           # Menu driver & user interface
└── README.md          # Project documentation
```
---

## Key Features

```
Feature                          Description
------------------------------------------------------------------------
- Add Book	                     Add new books with title, author, genre
- Update Book	                 Modify existing book details
- Delete Book	                 Remove book (only if not issued)
- Register Member	             Add new library members
- Update Member	                 Modify member information
- Delete Member	                 Remove member from system
- Issue Book	                 Issue book with due date calculation
- Return Book	                 Process return with fine calculation (₹2/day)
- Search by Title	             Find books by title keyword
- Search by Author	             Find books by author keyword
- Search by Genre	             Find books by genre keyword
- List Issued Books	             View all currently borrowed books
- Overdue Report	             Generate report sorted by fine amount
- AI Suggestions	             Rule-based recommendations on return
```

---
