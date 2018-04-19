int main_autopilot();
int main_flybywire();

typedef int (*functionPtr)();

typedef struct task {
    char *name;
    functionPtr function;
    struct task* next_task;
} task;

task fly_by_wire = { .name = "flybywire", .function = &main_flybywire, .next_task = 0 };
task tasks_to_execute = { .name = "autopilot", .function = &main_autopilot, .next_task = &fly_by_wire };
