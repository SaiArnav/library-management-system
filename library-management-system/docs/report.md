# Library Book Issue & Return System – Project Report

## 1. Overview
A console-based library management system written in C. It manages books, members, issue/return transactions, calculates overdue fines (₹2/day), and provides a rule-based AI recommendation engine.

## 2. Features
- Book: Add, Update, Delete, Display
- Member: Register, Update, Delete, Display
- Issue/Return books with due date tracking
- Fine calculation: ₹2 per overdue day
- Search by Title, Author, Genre (case-insensitive)
- Reports: Issued books, Overdue books, Member fines, Fine summary
- AI Recommendation: After return, suggests 3 available books with same author/genre
- Persistent storage: Binary files (`books.dat`, `members.dat`, `issued.dat`)

## 3. File Structure
```
library-management-system/
├── src/
│ ├── main.c, library.c, recommendation.c
│ ├── book.c, member.c, search.c
│ ├── issue.c, fine.c
│ └── *.h files
├── data/
│ ├── books.dat, members.dat, issued.dat
├── docs/
│ ├── proposal.md, report.md, flowchart.png, screenshots/
└── output/
│ ├── member_report.txt, fine_report.txt, issue_report.txt, overdue_report.txt
```

## 4. System Flow
1. User runs `./library` → Main menu (19 options)
2. User selects option
3. Program updates in-memory arrays
4. Data saved to binary files
5. Output displayed on console

## 5. Sample Output

**Issue Book:**
```
===== ISSUE BOOK =====
Enter Book ID: 1
Enter Member ID: 1
Enter Due Days: 7
Book Issued Successfully!
Issue ID: 1
Due Date: Sun Jun 6 15:30:00 2026
```

**Return Book with Fine:**
```
===== RETURN BOOK =====
Enter Issue ID: 1
Book Returned Successfully!
Fine Amount: Rs. 10

YOU MIGHT ALSO ENJOY:
The Hobbit by J.R.R. Tolkien (Fantasy)
The Silmarillion by J.R.R. Tolkien (Fantasy)
```

## 6. How to Compile & Run
```bash
cd src
gcc -o library main.c library.c recommendation.c book.c member.c search.c issue.c fine.c
./library

7. Test Cases:
```
Test			Input					Expected Output	Result
--------------------------------------------------------------------------------------------------
Add Book		Title: "1984", Author: "Orwell"		"Book added successfully! ID: 1"	
Issue Book		Book ID:1, Member ID:1, Days:7		"Book issued successfully!"	
Return Overdue		Issue ID:1				 Fine amount displayed	
Search			"Orwell"				 Shows 1984	
```

8. Challenges Faced & Solutions:
```
Challenge				Solution
---------------------------------------------------------------------------------
Binary file compatibility across OS	Used fixed-size structs with no padding
Date calculation across months		Used time_t and difftime()
Dynamic array resizing			Used realloc() with capacity doubling
```
9. Limitations & Future Enhancements
```
Current Limitations:

    1) No multi-user support

    2) Data not encrypted

    3) No GUI

Future Enhancements:

    1) Web interface using Flask

    2) Database (MySQL/SQLite) instead of binary files

    3) Email notifications for overdue books

    4) Barcode scanning for book ID

10. Team Contributions:

```
Role				Name
------------------------------------------
Core Library & AI		Arnav
Book, Member & Search		Govardhan
Issue, Fine & Reports		Shrejal
Documentation			Bhavya
Output Management		Ganesh
```
11. Conclusion

The system successfully automates essential library tasks with a simple console interface, robust file persistence, and an intelligent recommendation feature. All 19 menu options work as expected, and data persists between sessions.
