# 🔐 Password Vault – C++ Project

This is a terminal-based **Password Vault** written in **C++** that lets you safely store, view, and manage login credentials like website, username, and password. The vault uses a 4-digit PIN for access and includes a basic password strength checker.

---

## 📸 Preview (Terminal UI)

```
Welcome To The Vault
Press Enter To View Options...

1. Add Credential
2. View Saved Credentials
3. Delete Credential
4. Check Password Strength
5. Exit
```

---

## 🧠 Features

- 🔒 4-digit PIN authentication to access the vault
- 📝 Add login credentials (Website, Username, Password)
- 📂 View saved credentials in a structured format
- 🗑️ Delete any saved credentials by selecting an entry
- 💪 Password strength analyzer (based on length)
- 🔁 Looped menu for continued use until exit

---

## 🛠️ Built With

- **Language**: C++
- **Concepts Used**:
  - `struct` for storing credentials
  - Arrays for storing multiple entries
  - User-defined functions
  - Control flow (`if`, `switch`, `do-while`)
  - Basic terminal UI and formatting (`system("cls")`, `std::setw`)
  - Input validation (`isdigit`, length checks)

---

## 🧪 How to Compile and Run

### 🔧 Compile (using g++)
```bash
g++ -o vault vault.cpp
```

### ▶️ Run
```bash
./vault
```

You’ll be prompted to enter a **4-digit numeric PIN**. This acts as the gate to the vault. If the input is invalid (letters or incorrect length), access will be denied.

---

## 🔐 Password Strength Checker

This feature evaluates your saved password based on its **length**:

| Length         | Strength  |
|----------------|-----------|
| < 6 characters | Weak      |
| 6–9 characters | Moderate  |
| 10+ characters | Strong    |

✅ You can extend this logic further by checking for:
- Uppercase letters
- Digits
- Symbols (like `!@#`)
- Mixed casing

---

## 🔥 Possible Enhancements

These are great next steps for future upgrades:

- 💾 Add file handling (read/write credentials to a file)
- 🧊 Encrypt saved passwords for better security
- 🔐 Replace 4-digit PIN with hashed master password
- 🧱 Rewrite the project using C++ **OOP and classes**
- 🖥️ Add GUI using libraries like **Qt** or **SFML**
- 🧪 Add password generation feature
- 🌐 Allow exporting/importing credentials as `.txt` or `.csv`

---

## 👨‍💻 Author

**Boitumelo Clement Mkhondo**  
🎧 Also known as **BelmireDub** – deep house producer & aspiring full stack developer.

> _"I code like I produce beats – with flow and detail."_  
📍 South Africa

GitHub: [@Boitumelo-09](https://github.com/Boitumelo-09)

---

## 📄 License

This project is licensed under the **MIT License**.

```
MIT License

Copyright (c) 2025 Boitumelo

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files...
```

---

## 💬 Feedback

Feel free to fork, improve or share feedback. I’m still learning and growing, and every contribution or suggestion helps.
