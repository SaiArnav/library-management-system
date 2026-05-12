                             library-management-system: 
# 📚 Library Management System

A complete web-based Library Management System that mimics real-world library operations. It manages books, members, and book issuance/returns using a hybrid architecture:
 
- 🌐 Python Flask for REST API  
- 🎨 HTML/CSS/JavaScript for frontend UI  

The system includes persistent storage using binary files and a responsive dashboard for real-time library tracking.

---

## 📌 Features

- 📖 Book Management (Add, Search, View Books)
- 👤 Member Management (Register Members with Unique IDs)
- 🔄 Issue & Return System with Due Date Tracking
- 💾 Persistent Storage using `.txt` text files
- 📊 Real-time Reports Dashboard
- 🌐 RESTful API using Flask
- 📱 Responsive Web Interface (6 Pages)

---

## 📁 Project Structure

```
library-management-system/
│
├── backend/
│   └── app.py                 # Flask API (only backend file needed)
│
├── data/
│   ├── books.txt              # Stores books (ID|Title|Author|Genre|Available)
│   ├── members.txt            # Stores members (ID|Name)
|   └── issued.txt             # Stores issued books (BookID|MemberID|MemberName|IssueDate|DueDate)
│
├── frontend/
│   ├── index.html             # Dashboard homepage
│   ├── register.html          # Register members page
│   ├── search.html            # Search books page
│   ├── issue.html             # Issue/Return books page
│   ├── reports.html           # Reports page
│   ├── style.css              # All styling
│   ├── main.js                # All JavaScript logic
│   └── api.js                 # API calls to Flask
│
├── requirements.txt           # Python packages (flask, flask-cors)
└── run.bat                    # One-click startup script

```

---

## ⚙️ Setup Instructions

```
# 1️⃣ Clone the repository
git clone https://github.com/your-username/library-management-system.git
cd library-management-system

# 2️⃣ Install Python dependencies
pip install -r requirements.txt

# 3️⃣ Run the Flask backend server
python backend/app.py

# 4️⃣ Open the application in browser
http://localhost:5000
---
```
## 🕹️ Pages Overview
```
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
```
---

## 📡 API Endpoints
```
| Method | Endpoint             | Description                        |
|--------|----------------------|------------------------------------|
| GET    | /api/books           | Fetch all books in the library     |
| GET    | /api/books/search?q= | Search books by title or author    |
| POST   | /api/members         | Register a new member              |
| GET    | /api/members         | Retrieve all registered members    |
| POST   | /api/issue           | Issue a book to a member           |
| POST   | /api/return          | Return a borrowed book             |
| GET    | /api/reports/issued  | Get list of currently issued books |
| GET    | /api/reports/books   | Get complete book inventory        |
| GET    | /api/reports/members | Get all member details             |

```
---
## 🧠 Technology Stack
```
| Layer      | Technology            | Purpose                             |
|------------|-----------------------|-------------------------------------|
| Frontend   | HTML, CSS, JavaScript | User interface and interactivity    |
| Backend    | Python Flask          | REST API and request handling       |
| Storage    | Binary `.dat` files   | Persistent data storage             |
```
---
## Acknowledgments
Mentor: Rachamalla Sai Arnav Goud - 25881A05DW<br>
Leader: Cheera Shrejal 	          - 25881A05DY<br>
        Bachu Bhavya Sri          - 25881A05CM<br>
        Vadithyavath Ganesh       - 25881A05CR<br>
        Kummari Govardhan 	      - 25881A05CS<br>

Institution: Vardhaman College of Engineering
