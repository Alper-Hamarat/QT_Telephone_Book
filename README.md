# Telephone Book Qt Application

## Overview

This project is a simple telephone book application written in C++ using the Qt framework.

The main goal of the project was to practice:

- Qt Widgets
- Signal and Slot communication
- MVC architecture
- CRUD operations
- Object-oriented programming in C++
- Separation of responsibilities between View, Controller and Model

The application allows users to:

- Add entries
- View entries
- Edit entries
- Delete entries
- Display all stored entries

---

# Technologies

- C++
- Qt Widgets
- Qt Signals & Slots
- MVC Architecture
- STL (`std::vector`)

---

# Architecture

The application is structured using a simple MVC pattern.

## Model

`TelephoneBookModel`

Responsible for:

- Storing entries
- Managing CRUD operations
- Providing access to stored data

## View

`TelephoneBookMainView`

Responsible for:

- Displaying UI elements
- Handling user interaction
- Emitting signals to the controller

## Controller

`TelephoneBookController`

Responsible for:

- Connecting View and Model
- Handling application logic
- Updating the UI after model changes

## Entry

`Entry`

Represents a single telephone book entry containing:

- Name
- Phone number
- Address

---

# Features

## CRUD Operations

### Add Entry

Create and store new telephone book entries.

### Get Entry

Select and display an existing entry.

### Get All Entries

Load and display all entries in the list widget.

### Edit Entry

Modify existing entries.

### Delete Entry

Remove entries from the model.

---

# GUI

The GUI was implemented using Qt Widgets.

Main UI elements:

- `QListWidget`
- `QLineEdit`
- `QPushButton`
- Qt Signals & Slots

---

# Example Workflow

1. User selects an entry in the list.
2. The View emits a signal.
3. The Controller processes the request.
4. The Model returns or updates data.
5. The View refreshes the displayed information.

---

# Project Structure

```text
.
├── Entry
├── TelephoneBookModel
├── TelephoneBookController
├── TelephoneBookMainView
└── main.cpp
```

---

# Future Improvements

Possible future extensions:

- Persistent file storage
- JSON serialization
- Unique IDs instead of names
- Search functionality
- Sorting
- Qt Model/View framework (`QAbstractListModel`)
- Validation and error dialogs

---

# Learning Goals

This project was created primarily as a learning project to improve:

- Qt development skills
- MVC understanding
- Event-driven programming
- C++ project structure
- UI interaction handling

---

# Build

The project can be opened and built using:

- Qt Creator
- qmake or CMake

Example:

```bash
qmake
make
```

or using Qt Creator directly.

---

# Author

Developed as a personal C++/Qt learning project.
