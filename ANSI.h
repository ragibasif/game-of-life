// Reset all attributes
#define ANSI_RESET "\x1b[0m"

// Text colors
#define ANSI_BLACK "\x1b[30m"
#define ANSI_RED "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_BLUE "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN "\x1b[36m"
#define ANSI_WHITE "\x1b[37m"
#define ANSI_DEFAULT "\x1b[39m"

// Background colors
#define ANSI_BG_BLACK "\x1b[40m"
#define ANSI_BG_RED "\x1b[41m"
#define ANSI_BG_GREEN "\x1b[42m"
#define ANSI_BG_YELLOW "\x1b[43m"
#define ANSI_BG_BLUE "\x1b[44m"
#define ANSI_BG_MAGENTA "\x1b[45m"
#define ANSI_BG_CYAN "\x1b[46m"
#define ANSI_BG_WHITE "\x1b[47m"
#define ANSI_BG_DEFAULT "\x1b[49m"

// Bright text colors
#define ANSI_BRIGHT_BLACK "\x1b[90m"
#define ANSI_BRIGHT_RED "\x1b[91m"
#define ANSI_BRIGHT_GREEN "\x1b[92m"
#define ANSI_BRIGHT_YELLOW "\x1b[93m"
#define ANSI_BRIGHT_BLUE "\x1b[94m"
#define ANSI_BRIGHT_MAGENTA "\x1b[95m"
#define ANSI_BRIGHT_CYAN "\x1b[96m"
#define ANSI_BRIGHT_WHITE "\x1b[97m"

// Bright background colors
#define ANSI_BG_BRIGHT_BLACK "\x1b[100m"
#define ANSI_BG_BRIGHT_RED "\x1b[101m"
#define ANSI_BG_BRIGHT_GREEN "\x1b[102m"
#define ANSI_BG_BRIGHT_YELLOW "\x1b[103m"
#define ANSI_BG_BRIGHT_BLUE "\x1b[104m"
#define ANSI_BG_BRIGHT_MAGENTA "\x1b[105m"
#define ANSI_BG_BRIGHT_CYAN "\x1b[106m"
#define ANSI_BG_BRIGHT_WHITE "\x1b[107m"

// Text attributes
#define ANSI_BOLD "\x1b[1m"
#define ANSI_DIM "\x1b[2m"
#define ANSI_ITALIC "\x1b[3m"
#define ANSI_UNDERLINE "\x1b[4m"
#define ANSI_BLINK "\x1b[5m"
#define ANSI_REVERSE "\x1b[7m"
#define ANSI_HIDDEN "\x1b[8m"
#define ANSI_STRIKETHROUGH "\x1b[9m"

// Reset specific attributes
#define ANSI_NO_BOLD "\x1b[21m" // or "\x1b[22m" (both work)
#define ANSI_NO_ITALIC "\x1b[23m"
#define ANSI_NO_UNDERLINE "\x1b[24m"
#define ANSI_NO_BLINK "\x1b[25m"
#define ANSI_NO_REVERSE "\x1b[27m"
#define ANSI_NO_HIDDEN "\x1b[28m"
#define ANSI_NO_STRIKETHROUGH "\x1b[29m"

// Cursor movement
#define ANSI_CURSOR_UP(n) "\x1b[" #n "A"
#define ANSI_CURSOR_DOWN(n) "\x1b[" #n "B"
#define ANSI_CURSOR_FORWARD(n) "\x1b[" #n "C"
#define ANSI_CURSOR_BACK(n) "\x1b[" #n "D"
#define ANSI_CURSOR_NEXT_LINE(n) "\x1b[" #n "E"
#define ANSI_CURSOR_PREV_LINE(n) "\x1b[" #n "F"
#define ANSI_CURSOR_COLUMN(n) "\x1b[" #n "G"
#define ANSI_CURSOR_POSITION(row, col) "\x1b[" #row ";" #col "H"

// Save and restore cursor position
#define ANSI_CURSOR_SAVE "\x1b[s"
#define ANSI_CURSOR_RESTORE "\x1b[u"

// Cursor visibility
#define ANSI_CURSOR_HIDE "\x1b[?25l"
#define ANSI_CURSOR_SHOW "\x1b[?25h"

// Screen operations
#define ANSI_SCREEN_CLEAR "\x1b[2J"
#define ANSI_SCREEN_CLEAR_LINE "\x1b[2K"
#define ANSI_SCREEN_CLEAR_TO_END "\x1b[0J"
#define ANSI_SCREEN_CLEAR_TO_START "\x1b[1J"
#define ANSI_LINE_CLEAR_TO_END "\x1b[0K"
#define ANSI_LINE_CLEAR_TO_START "\x1b[1K"
#define ANSI_SCROLL_UP(n) "\x1b[" #n "S"
#define ANSI_SCROLL_DOWN(n) "\x1b[" #n "T"

// Terminal modes
#define ANSI_ALTERNATE_BUFFER "\x1b[?1049h"
#define ANSI_MAIN_BUFFER "\x1b[?1049l"
#define ANSI_LINE_WRAP_ON "\x1b[?7h"
#define ANSI_LINE_WRAP_OFF "\x1b[?7l"
