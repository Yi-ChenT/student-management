# 🎓 Student Management System
## 🗂 Project Overview
This console‑based Student Management System lets you collect, analyse, and persist essential data for a small class (up to 30 students, 5 subjects each) using nothing more than standard C.
It demonstrates structured data handling with struct, robust string/file I/O, and basic algorithms for search, sort, and statistics—all packaged in a clear, menu‑driven UI.

## Core Capabilities
|Action                 |	Menu Option |	Process                                                   |
|-----------------------|---------------|-------------------------------------------------------------|
|Add Student	        |1	            |Capture name, ID, and 5 subject marks → auto‑compute average.|
|Search by Name	        |2	            |Instant lookup by exact name match.                          |
|Edit Grades	        |3	            |Overwrite a student’s 5 marks, recalculating the average.    |
|Display All (Sorted)	|4	            |Bubble‑sort by average (descending) then print a neat roster.|
|Save to File	        |5	            |Persist every record to students.txt (human‑readable format).|
|Load from File	        |6	            |Re‑hydrate records from students.txt into memory.            |
|Exit	                |7	            |Quit the application gracefully.                             |

## Implementation Highlights
- Data Model – typedef struct Student holding name, ID, five grades, and a cached average.

- String Safety – uses fgets, strncpy_s, strcmp, etc., to avoid buffer overruns.

- File I/O – use safe version function fopen_s plus structured fprintf / fgets / sscanf_s parsing.

- Algorithms – custom bubble sort (descending averages) and linear search by name.

- Defensive Coding – caps on class size, newline stripping, and format validation during load.

<hr/>
 
Feel free to clone, fork, or extend—add GPA weighting, CSV export, or a GUI front‑end!
