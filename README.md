**# -Project-For-Blood-Groups-Management-System** 
A **C++ console application** to manage blood donor records. The system allows adding, viewing, searching, updating, and deleting donor information, as well as checking blood donation compatibility.
<img width="976" height="506" alt="Image" src="https://github.com/user-attachments/assets/e904a07b-5ac2-480a-ba47-dec06214655d" />###
**## What the Project Does***

This project provides a **complete blood donor management solution** that allows users to:

- Add new donor records with details like Name, Blood Group, Age, and Gender.
- View all stored donor records.
- Search for specific records by Name or Blood Group.
- Update existing donor information.
- Delete donor records.
- Check blood donation compatibility based on blood group rules.
- <img width="969" height="510" alt="Image" src="https://github.com/user-attachments/assets/f73f79f0-3330-4a83-8b6b-c801dfd2171c" />

The project uses **file handling** to store records in a text file (`blood_data.txt`) so that data persists between sessions.

---

## Why the Project is Useful

- Helps **blood banks, hospitals, and donation drives** keep track of donors efficiently.
- Provides a **quick reference** to check which blood groups are compatible for donation.
- Demonstrates **core C++ concepts**: file handling, functions, loops, conditional statements, and string manipulation.
- Serves as a **learning tool** for beginners to understand modular programming and data management in C++.

---

## Features

- **Add Record:** Enter and save donor details.
- **View Records:** Display all donors.
- **Search Record:** Find donors by Name or Blood Group.
- **Update Record:** Modify existing donor information.
- **Delete Record:** Remove a donor from the system.
- **Blood Donation Compatibility:** Check which blood groups a donor can safely donate to.
<img width="976" height="506" alt="Image" src="https://github.com/user-attachments/assets/e904a07b-5ac2-480a-ba47-dec06214655d" />###
---

## Blood Donation Compatibility

| Donor | Can Donate To |
|-------|---------------|
| O-    | All Blood Groups |
| O+    | O+, A+, B+, AB+ |
| A-    | A-, A+, AB-, AB+ |
| A+    | A+, AB+ |
| B-    | B-, B+, AB-, AB+ |
| B+    | B+, AB+ |
| AB-   | AB-, AB+ |
| AB+   | AB+ only |
<img width="882" height="506" alt="Image" src="https://github.com/user-attachments/assets/29d61abd-0fb9-4911-998f-182ba79f450f" />
---
Exit.
<img width="882" height="506" alt="Image" src="https://github.com/user-attachments/assets/a1bd1da4-1b31-41e5-8457-5ecc4ae1278c" />
## Getting Started

### Prerequisites

- C++ compiler (e.g., **g++**, **Visual Studio**, **Code::Blocks**)

### Installation

1. **Clone the repository:**

```bash
git clone https://github.com/yourusername/blood-group-management.git
