int main_autopilot();

typedef void (*functionPtr)();

typedef struct task {
    char *name;
    functionPtr function;
    task* next_task;
} task;

task tasks_to_execute = { .name = "autopilot", .function = &main_autopilot, .next_task = NULL };