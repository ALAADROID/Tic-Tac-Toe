
# Tic-Tac-Toe Game in C++

A cross-platform, console-based Tic-Tac-Toe game featuring custom rendering interfaces, comprehensive input validation, and dedicated gameplay tracks against an automated computer opponent or a second physical player.

## 🆕 Latest Update (v1.0.1)  

This release focuses on code maintainability and documentation. The core game logic remains stable, with improved code readability and standardized inline documentation to facilitate future contributions and ease of navigation.


## Features

✅ **Dual Gameplay Tracks:** Supports both Single Player (vs. PC-Alaa-Droid) and local Two-Player competitive modes.  
✅ **Robust Input Validation:** Actively handles incorrect coordinate boundaries and catches stream errors caused by entering characters instead of numbers.  
✅ **Dynamic Layout Architecture:** Renders a clean UTF-8 console interface board detailing live coordinate maps.  
✅ **Randomized Game Seed Engine:** Uses internal Unix timestamps to guarantee unique automated computer move paths each game.  
✅ **Written in Pure C++:** Utilizes standard library operations for clean performance and execution.  

## How It Works

1. The user selects a game execution path (1 for Single Player, 2 for Two-Player).  
2. Competitors enter names to personalize victory declarations and active prompt lines.  
3. Players input raw row and column values sequentially (values 1 through 3).  
4. The system updates the localized map grid matrix, checks for valid combinations, and handles draw mechanics gracefully.  

## 📥 Cloning the Repository

To get started, clone this repository using Git:
```bash
git clone [https://github.com/ALAADROID/Tic-Tac-Toe.git](https://github.com/ALAADROID/Tic-Tac-Toe.git)
cd Tic-Tac-Toe
```

### 🛠️ Compilation
To compile the program, use an optimized G++ configuration:

```bash
g++ -o tic_tac_toe main.cpp
```

## 🚀 Running the Program
After compiling, execute the binary via your console:

```bash
./tic_tac_toe
```

## 📌 Notes
Ensure your console environment supports UTF-8 character encoding and ANSI escape codes to render the layout borders and text font weights correctly.

On Windows systems, you can execute the program smoothly using modern terminal emulators, PowerShell configurations, or WSL (Windows Subsystem for Linux).

---

**Developed by [ALAADROID](https://github.com/ALAADROID)**
