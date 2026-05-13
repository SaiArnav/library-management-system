//SHOWMESSAGE
function showMessage(elementId, success, message) {
    // Find the box on the page where we want to show the message
    const div = document.getElementById(elementId);
    if (!div) return;  // If box doesn't exist, stop
    
    // Add some styling to make the message look nice
    div.style.padding = "10px 13px";
    div.style.borderRadius = "8px";
    div.style.marginTop = "10px";
    
    // If success = true → show green message
    if (success) {
        div.style.background = "#e8f5ed";
        div.style.color = "#2d5a3d";
        div.innerHTML = "✅ " + message;
    } 
    // If success = false → show red error message
    else {
        div.style.background = "#fde8e8";
        div.style.color = "#c0392b";
        div.innerHTML = "❌ " + message;
    }
    
    // Automatically hide the message after 3 seconds
    setTimeout(() => {
        div.innerHTML = "";
        div.style.padding = "0";
    }, 3000);
}
// ========== DASHBOARD STATS (for index.html) ==========
async function loadStats() {
    try {
        // Ask the backend for the latest statistics
        const result = await apiGetStats();
        
        if (result.success) {
            // Update "Total Books" number on the page
            if (document.getElementById("totalBooks"))
                document.getElementById("totalBooks").innerText = result.stats.total_books || 0;
            
            // Update "Total Members" number
            if (document.getElementById("totalMembers"))
                document.getElementById("totalMembers").innerText = result.stats.total_members || 0;
            
            // Update "Issued Books" number
            if (document.getElementById("totalIssued"))
                document.getElementById("totalIssued").innerText = result.stats.issued_books || 0;
            
            // Update "Overdue Books" number
            if (document.getElementById("totalOverdue"))
                document.getElementById("totalOverdue").innerText = result.stats.overdue_books || 0;
        }
    } catch(e) {
        console.log("Stats error:", e);
    }
}
// ========== BOOK DISPLAY (for index.html search) ==========
function displayBooks(books, containerId) {
    // Find the container where books should be displayed
    const container = document.getElementById(containerId);
    if (!container) return;
    
    // If no books, show a message
    if (!books || books.length === 0) {
        container.innerHTML = "
No books found

";
        return;
    }
    
    // Colors for book covers (just for fun)
    const colors = ["#6b5b95", "#2980b9", "#27ae60", "#e67e22", "#c0392b"];
    
    // Create HTML for each book and put them together
    container.innerHTML = books.map((book, i) => `
        

            

            

                
${escapeHtml(book.title)}

                
${escapeHtml(book.author)} · ${escapeHtml(book.genre)} · ${escapeHtml(book.id)}

            

            
                ${book.available ? 'Available' : 'Issued'}
            
        

    `).join("");
}
// ========== SEARCH FUNCTIONS (for index.html & search.html) ==========
let searchBy = "title";  // Default: search by title

// Changes what we search by (Title, Author, or ID)
function setTab(btn, mode) {
    document.querySelectorAll(".ftab").forEach(t => t.classList.remove("active"));
    btn.classList.add("active");
    searchBy = mode;  // Now search by whatever tab was clicked
}

// Actually performs the search
async function doSearch() {
    // Get what the user typed
    const query = document.getElementById("searchInput")?.value.trim();
    if (!query) return;  // If nothing typed, do nothing
    
    // Ask backend to search
    const result = await apiSearchBooks(query, searchBy);
    
    // Show results
    if (result.success && result.data) {
        displayBooks(result.data, "searchResults");
    } else {
        const container = document.getElementById("searchResults");
        if (container) container.innerHTML = "
No results found

";
    }
}
// ========== ADD BOOK (for index.html) ==========
async function addNewBook() {
    // Get values from the input boxes
    const id = document.getElementById("bookID")?.value.trim();
    const title = document.getElementById("bookTitle")?.value.trim();
    const author = document.getElementById("bookAuthor")?.value.trim();
    const genre = document.getElementById("bookGenre")?.value.trim();
    
    // Check if any field is empty
    if (!id || !title || !author || !genre) {
        showMessage("addBookResult", false, "Please fill all fields");
        return;
    }
    
    // Send to backend to save
    const result = await apiAddBook(id, title, author, genre);
    showMessage("addBookResult", result.success, result.message);
    
    if (result.success) {
        // Clear the form inputs
        if (document.getElementById("bookID")) document.getElementById("bookID").value = "";
        if (document.getElementById("bookTitle")) document.getElementById("bookTitle").value = "";
        if (document.getElementById("bookAuthor")) document.getElementById("bookAuthor").value = "";
        if (document.getElementById("bookGenre")) document.getElementById("bookGenre").value = "";
        
        // Refresh everything
        if (typeof loadBooks === 'function') loadBooks();
        loadStats();
        
        // Refresh search if there was one
        if (document.getElementById("searchInput")?.value) {
            doSearch();
        }
    }
}
// ========== REGISTER MEMBER (for register.html) ==========
async function registerMember() {
    const id = document.getElementById("memberID")?.value.trim();
    const name = document.getElementById("memberName")?.value.trim();
    
    if (!id || !name) {
        showMessage("registerResult", false, "Please fill all fields");
        return;
    }
    
    const result = await apiRegisterMember(id, name);
    showMessage("registerResult", result.success, result.message);
    
    if (result.success) {
        if (document.getElementById("memberID")) document.getElementById("memberID").value = "";
        if (document.getElementById("memberName")) document.getElementById("memberName").value = "";
        loadStats();
        if (typeof loadMembers === 'function') loadMembers();
    }
}
// ========== ISSUE BOOK (for issue.html & index.html) ==========
async function issueBook() {
    const bookId = document.getElementById("issueBookID")?.value.trim();
    const memberId = document.getElementById("issueMemberID")?.value.trim();
    
    if (!bookId || !memberId) {
        showMessage("issueResult", false, "Please enter both Book ID and Member ID");
        return;
    }
    
    const result = await apiIssueBook(bookId, memberId);
    showMessage("issueResult", result.success, result.message);
    
    if (result.success) {
        if (document.getElementById("issueBookID")) document.getElementById("issueBookID").value = "";
        if (document.getElementById("issueMemberID")) document.getElementById("issueMemberID").value = "";
        loadStats();
        if (typeof loadOverdue === 'function') loadOverdue();
        if (typeof loadIssued === 'function') loadIssued();
        
        if (document.getElementById("searchInput")?.value) {
            doSearch();
        }
    }
}
// ========== RETURN BOOK (for issue.html & index.html) ==========
async function returnBook() {
    const bookId = document.getElementById("returnBookID")?.value.trim();
    
    if (!bookId) {
        showMessage("returnResult", false, "Please enter Book ID");
        return;
    }
    
    const result = await apiReturnBook(bookId);
    showMessage("returnResult", result.success, result.message);
    
    // If there is a fine, show it
    if (result.fine && result.fine > 0) {
        const fineDiv = document.getElementById("fineDisplay");
        if (fineDiv) {
            fineDiv.style.display = "block";
            fineDiv.innerHTML = "⚠️ Fine: Rs. " + result.fine;
            setTimeout(() => fineDiv.style.display = "none", 5000);
        }
    }
    
    if (result.success) {
        if (document.getElementById("returnBookID")) document.getElementById("returnBookID").value = "";
        loadStats();
        if (typeof loadOverdue === 'function') loadOverdue();
        if (typeof loadIssued === 'function') loadIssued();
        
        if (document.getElementById("searchInput")?.value) {
            doSearch();
        }
    }
}
// ========== OVERDUE BOOKS (for index.html & reports.html) ==========
async function loadOverdue() {
    const container = document.getElementById("overdueList");
    if (!container) return;
    
    const result = await apiGetOverdueBooks();
    
    if (!result.success || !result.data || result.data.length === 0) {
        container.innerHTML = "
No overdue books

";
        return;
    }
    
    const colors = ["#6b5b95", "#2980b9", "#27ae60", "#e67e22", "#c0392b"];
    
    container.innerHTML = result.data.map((item, i) => `
        

            

                

                    ${escapeHtml(item.member_name?.charAt(0) || "?")}
                

                

                    
${escapeHtml(item.member_name)}

                    
${escapeHtml(item.book_id)} — ${item.days_overdue} days late

                

            

            Rs.${item.fine}
        

    `).join("");
}
async function loadIssued() {

    const container = document.getElementById("issuedList");

    if (!container) return;

    const result = await apiGetIssuedBooks();

    if (!result.success || !result.data || result.data.length === 0) {

        container.innerHTML =
            "<p style='color:#aaa;'>No issued books</p>";

        return;
    }

    container.innerHTML = result.data.map(book => `

        <div class="book-row">

            <div style="flex:1">

                <div class="b-title">
                    ${escapeHtml(book.title)}
                </div>

                <div class="b-meta">
                    Book ID: ${escapeHtml(book.book_id)}
                </div>

                <div class="b-meta">
                    Member ID: ${escapeHtml(book.member_id)}
                </div>

            </div>

            <span class="pill out">
                Issued
            </span>

        </div>

    `).join("");
}
async function loadMemberReport(memberId) {

    const container = document.getElementById("memberReport");

    if (!container) return;

    const result = await apiGetMemberReport(memberId);

    if (!result.success || !result.data || result.data.length === 0) {

        container.innerHTML =
            "<p style='color:#aaa;'>No books borrowed</p>";

        return;
    }

    container.innerHTML = result.data.map(book => `

        <div class="book-row">

            <div style="flex:1">

                <div class="b-title">
                    ${escapeHtml(book.title)}
                </div>

                <div class="b-meta">
                    Due Date: ${escapeHtml(book.due_date)}
                </div>

            </div>

        </div>

    `).join("");
}
async function deleteMember(memberId) {

    if (!confirm("Delete this member?"))
        return;

    const result = await apiDeleteMember(memberId);

    showMessage(
        "memberResult",
        result.success,
        result.message
    );

    if (result.success) {

        loadStats();

        if (typeof loadMembers === 'function') {

            loadMembers();
        }
    }
}
async function deleteBook(bookId) {

    if (!confirm("Delete this book?"))
        return;

    const result = await apiDeleteBook(bookId);

    showMessage(
        "bookResult",
        result.success,
        result.message
    );

    if (result.success) {

        loadStats();

        if (typeof loadBooks === 'function') {

            loadBooks();
        }
    }
}
function escapeHtml(text) {

    if (!text) return "";

    return text
        .replace(/&/g, "&amp;")
        .replace(/</g, "&lt;")
        .replace(/>/g, "&gt;")
        .replace(/"/g, "&quot;")
        .replace(/'/g, "&#039;");
}
