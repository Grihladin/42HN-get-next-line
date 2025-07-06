<div align="center">

# <img src="https://github.com/Grihladin/42-project-badges/blob/main/badges/get_next_linee.png" width="150" height="150"> 

</div>

**get_next_line**([42Heilbronn](https://www.42heilbronn.de/en/) project) is a C function that reads a file line by line, returning one line at a time with each function call. This project introduces the concept of static variables and efficient file reading in C.

## ✨ Features

- **Line-by-Line Reading**: Read any file descriptor one line at a time
- **Configurable Buffer Size**: Adjustable `BUFFER_SIZE` for optimal performance
- **Memory Efficient**: Uses static variables to maintain state between calls
- **Multiple File Descriptors**: Handle multiple files simultaneously
- **42 Norm Compliant**: Follows strict coding standards with no memory leaks

## 🚀 Usage

### Function Prototype

```c
char *get_next_line(int fd);
```

```bash
# Example usage:
int fd = open("file.txt", O_RDONLY);
char *line;
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

**Returns**: The next line from the file descriptor, or `NULL` when EOF is reached or an error occurs.

## 🔧 Core Functions

- **`get_next_line(int fd)`**: Main function that returns the next line
- **`read_and_merge(int fd, char *current_line)`**: Reads from fd and merges with existing content
- **`line_validator(char *s)`**: Extracts and validates a complete line
- **`ft_str_merge(char *s1, char *s2)`**: Merges two strings efficiently
- **`ft_strdup(const char *src)`**: Duplicates a string
- **`is_in_str(char *s, char c)`**: Checks if character exists in string
- **`ft_strlen(const char *s)`**: Calculates string length

## 📁 Project Structure

```
get_next_line/
├── get_next_line.h          # Header file with function prototypes
├── get_next_line.c          # Main implementation
├── get_next_line_utils.c    # Utility functions
└── README.md                # Project documentation
```

---

Made with ❤️ by **[mratke](https://github.com/Grihladin)** - 42 Heilbronn
