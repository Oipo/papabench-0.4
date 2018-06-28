int main_autopilot();
int main_flybywire();
int init_autopilot(int count, ...);
int init_flybywire(int count, ...);

typedef int (*functionPtr)();
typedef int (*initFunctionPtr)(int count, ...);

typedef struct task {
    char *name;
    functionPtr function;
    initFunctionPtr init;
    struct task* next_task;
} task;

task fly_by_wire = { .name = "flybywire", .function = &main_flybywire, .init = &init_flybywire, .next_task = 0 };
task fly_by_wire2 = { .name = "flybywire_different_arguments", .function = &main_flybywire, .init = &init_flybywire, .next_task = &fly_by_wire };
task tasks_to_execute = { .name = "autopilot", .function = &main_autopilot, .init = &init_autopilot, .next_task = &fly_by_wire2 };
