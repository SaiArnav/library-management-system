                             library-management-system: 
# 📚 Library Management System

A complete web-based Library Management System that mimics real-world library operations. It manages books, members, and book issuance/returns using a hybrid architecture:

- ⚙️ C++ for core logic  
- 🌐 Python Flask for REST API  
- 🎨 HTML/CSS/JavaScript for frontend UI  

The system includes persistent storage using binary files and a responsive dashboard for real-time library tracking.

---

## 📌 Features

- 📖 Book Management (Add, Search, View Books)
- 👤 Member Management (Register Members with Unique IDs)
- 🔄 Issue & Return System with Due Date Tracking
- 💾 Persistent Storage using `.dat` binary files
- 📊 Real-time Reports Dashboard
- 🌐 RESTful API using Flask
- ⚡ High-performance C++ backend logic
- 📱 Responsive Web Interface (6 Pages)



## 📁 Project Structure


library-management-system/
│
├── backend/
│ ├── app.py # Flask main application
│ ├── config.py # Configuration settings
│ └── cpp/
│ ├── library.cpp # C++ core logic
│ ├── library.h # Header file
│ └── Makefile # Build automation
│
├── data/
│ ├── books.dat # Book records
│ ├── members.dat # Member records
│ └── issued.dat # Issued books records
│
├── frontend/
│ ├── index.html # Dashboard
│ ├── register.html # Add members
│ ├── search.html # Search books
│ ├── issue.html # Issue books
│ ├── return.html # Return books
│ ├── reports.html # Reports page
│ ├── style.css # Styling
│ ├── main.js # Frontend logic
│ └── api.js # API integration
│
├── requirements.txt # Python dependencies
├── run.bat # Windows startup script
└── README.md


---

---

## ⚙️ Setup Instructions

```bash
# 1️⃣ Clone the repository
git clone https://github.com/your-username/library-management-system.git
cd library-management-system

# 2️⃣ Build the C++ backend
cd backend/cpp
make
cd ../..

# 3️⃣ Install Python dependencies
pip install -r requirements.txt

# 4️⃣ Run the Flask backend server
python backend/app.py

# 5️⃣ Open the application in browser
http://localhost:5000


## 🕹️ Pages Overview

- 🏠 **Home (index.html)**  
  Dashboard showing overall library statistics and quick navigation

- 👤 **Register Member (register.html)**  
  Add new members with name, contact details, and generate unique ID

- 🔍 **Search (search.html)**  
  Search books and members by title, author, or ID

- 📤 **Issue Book (issue.html)**  
  Issue a book to a registered member with due date generation

- 📥 **Return Book (return.html)**  
  Process book returns and update availability status

- 📊 **Reports (reports.html)**  
  View complete data of books, members, and currently issued books


## 📡 API Endpoints

| Method | Endpoint | Description |
|--------|----------|-------------|
| GET | /api/books | Fetch all books in the library |
| GET | /api/books/search?q= | Search books by title or author |
| POST | /api/members | Register a new member |
| GET | /api/members | Retrieve all registered members |
| POST | /api/issue | Issue a book to a member |
| POST | /api/return | Return a borrowed book |
| GET | /api/reports/issued | Get list of currently issued books |
| GET | /api/reports/books | Get complete book inventory |
| GET | /api/reports/members | Get all member details | 
