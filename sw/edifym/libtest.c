int main_autopilot();

typedef int (*functionPtr)();

typedef struct task {
    char *name;
    functionPtr function;
    struct task* next_task;
} task;

task tasks_to_execute = { .name = "autopilot", .function = &main_autopilot, .next_task = 0 };