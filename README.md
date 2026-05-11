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

## ⚙️ Setup Instructions

### 1️⃣ Clone Repository
```bash
git clone https://github.com/your-username/library-management-system.git
cd library-management-system
2️⃣ Build C++ Backend
cd backend/cpp
make
cd ../..
3️⃣ Install Dependencies
pip install -r requirements.txt
4️⃣ Run Application
python backend/app.py
5️⃣ Open in Browser
http://localhost:5000
🕹️ Pages Overview
Page	Function
🏠 Home	Dashboard with statistics
👤 Register	Add new members
🔍 Search	Search books/members
📤 Issue	Issue a book
📥 Return	Return a book
📊 Reports	View library data
📡 API Endpoints
Method	Endpoint	Description
GET	/api/books	Get all books
GET	/api/books/search?q=	Search books
POST	/api/members	Add member
GET	/api/members	Get members
POST	/api/issue	Issue book
POST	/api/return	Return book
GET	/api/reports/issued	Issued books
GET	/api/reports/books	Book inventory
GET	/api/reports/members	Member list
🧠 Tech Stack
Layer	Technology
Frontend	HTML, CSS, JavaScript
Backend	Python Flask
Core Logic	C++
Storage	Binary .dat files
Build Tool	Make
👥 Team Members
Arnav – Backend & Flask Integration
Shrejal – C++ Core Logic
Govardhan – Frontend UI/UX Design
Ganesh – JavaScript & API Integration
Bhavya Sri – Documentation & Data Handling
📊 Sample Output
Book Issued Successfully!
────────────────────────────
Book: The Great Gatsby
Member: John Doe (ID: M001)
Issue Date: 2026-05-11
Due Date: 2026-05-25
────────────────────────────
🔮 Future Enhancements
💰 Fine calculation for late returns
🔐 Admin login system
📄 Export reports (PDF/CSV)
📧 Email notifications for due dates
🐳 Docker deployment
📚 Learning Outcomes
Full-stack integration (C++ + Flask + Web)
REST API development
File handling using binary storage
Frontend-backend communication
Team collaboration using Git/GitHub
🙏 Acknowledgments

Mentor: Rachamalla Sai Arnav Goud - 25881A05DW
Team Lead: Cheera Shrejal - 25881A05DY

Team Members:

Bhavya Sri - 25881A05CM
Ganesh - 25881A05CR
Govardhan - 25881A05CS

🏫 Vardhaman College of Engineering

