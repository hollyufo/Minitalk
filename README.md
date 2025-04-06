# 🧠 Minitalk

A simple UNIX signal-based client-server communication program written in C.

---

## 📖 Summary

**Minitalk** is a small project that simulates inter-process communication using only UNIX signals (`SIGUSR1` and `SIGUSR2`). The goal is to send a string from a client to a server, one bit at a time, using the allowed functions and system calls.

---

## 📦 Version

**3.2**

---

## 🛠️ Contents

- [🌿 Foreword](#-foreword)
- [⚙️ Common Instructions](#️-common-instructions)
- [📋 Project Instructions](#-project-instructions)
- [✅ Mandatory Part](#-mandatory-part)
- [✨ Bonus Part](#-bonus-part)
- [📦 Submission](#-submission)

---

## 🌿 Foreword

> **cis-3-Hexen-1-ol**, aka leaf alcohol, gives the smell of freshly cut grass and acts as an attractant for predatory insects. Like that compound, Minitalk is small yet powerful—just with C and signals.

---

## ⚙️ Common Instructions

- Must be written in **C** and follow **42 Norm**.
- Must be **memory-leak free** and **error-safe** (no crashes).
- A proper **Makefile** is required with these rules:
  - `all`, `clean`, `fclean`, `re`, `$(NAME)`
- If you use **libft**, place it in a `libft/` folder.
- You are encouraged to write **tests** (not submitted).
- Only submit through the **assigned Git repo**.

---

## 📋 Project Instructions

- Produce two executables: `client` and `server`
- Use only the following functions:
  - `write`, `ft_printf` (or your own)
  - `signal`, `sigemptyset`, `sigaddset`, `sigaction`
  - `kill`, `getpid`, `malloc`, `free`
  - `pause`, `sleep`, `usleep`, `exit`
- One global variable per executable is allowed (if needed)

---

## ✅ Mandatory Part

- **Server**:
  - Prints its PID on startup.
  - Receives string messages from clients and prints them immediately.
  - Handles multiple clients without restarting.
- **Client**:
  - Takes two arguments:
    - Server PID
    - Message string
  - Sends the message using **UNIX signals** only (`SIGUSR1` and `SIGUSR2`).
- Must work fast (100 chars should not take 1 second to print).

---

## ✨ Bonus Part

> *Will only be checked if the mandatory part is perfect.*

Bonus features:
- Server acknowledges each message received.
- Unicode character support.

---

## 📦 Submission

- Submit your code in the **designated Git repository**
- Only what is in the repo will be evaluated
- Double-check filenames and structure before pushing

---

💡 *Pro tip: Signals are tricky, timing is everything. Test often and cleanly!*
