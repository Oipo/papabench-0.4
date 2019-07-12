void program_init(void);

// autopilot tasks
void altitude_control_task(void);
int init_altitude_control_task(int arg_count, int *task_args);

void climb_control_task(void);
int init_climb_control_task(int arg_count, int *task_args);

void link_fbw_send(void);
int init_link_fbw_send(int arg_count, int *task_args);

void navigation_task( void );
int init_navigation_task(int arg_count, int *task_args);

void radio_control_task(void);
int init_radio_control_task(int arg_count, int *task_args);

void receive_gps_data_task(void);
int init_receive_gps_data_task(int arg_count, int *task_args);

void reporting_task(void);

void stabilisation_task(void);
int init_stabilisation_task(int arg_count, int *task_args);

// fly by wire tasks
void check_failsafe_task(void);
int init_check_failsafe_task(int arg_count, int *task_args);

void check_mega128_values_task(void);
int init_check_mega128_values_task(int arg_count, int *task_args);

void send_data_to_autopilot_task(void);
int init_send_data_to_autopilot_task(int arg_count, int *task_args);

void servo_transmit(void);

void test_ppm_task(void);
int init_test_ppm_task(int arg_count, int *task_args);

typedef void (*functionPtr)();
typedef int (*initFunctionPtr)(int count, int *task_args);

typedef struct task {
    char *name;
    functionPtr function;
    initFunctionPtr init;
    struct task* next_task;
} task;

task _altitude_control_task = { .name = "altitude_control_task", .function = &altitude_control_task, .init = &init_altitude_control_task, .next_task = 0 };
task _climb_control_task = { .name = "altitude_control_task", .function = &climb_control_task, .init = &init_climb_control_task, .next_task = &_altitude_control_task };
task _link_fbw_send = { .name = "link_fbw_send", .function = &link_fbw_send, .init = &init_link_fbw_send, .next_task = &_climb_control_task };
task _navigation_task = { .name = "navigation_task", .function = &navigation_task, .init = &init_navigation_task, .next_task = &_link_fbw_send };
task _radio_control_task = { .name = "radio_control_task", .function = &radio_control_task, .init = &init_radio_control_task, .next_task = &_navigation_task };
task _receive_gps_data_task = { .name = "receive_gps_data_task", .function = &receive_gps_data_task, .init = &init_receive_gps_data_task, .next_task = &_radio_control_task };
task _reporting_task = { .name = "reporting_task", .function = &reporting_task, .init = 0, .next_task = &_receive_gps_data_task };
task _stabilisation_task = { .name = "stabilisation_task", .function = &stabilisation_task, .init = &init_stabilisation_task, .next_task = &_reporting_task };
task _check_failsafe_task = { .name = "check_failsafe_task", .function = &check_failsafe_task, .init = &init_check_failsafe_task, .next_task = &_stabilisation_task };
task _check_mega128_values_task = { .name = "check_mega128_values_task", .function = &check_mega128_values_task, .init = &init_check_mega128_values_task, .next_task = &_check_failsafe_task };
task _send_data_to_autopilot_task = { .name = "send_data_to_autopilot_task", .function = &send_data_to_autopilot_task, .init = &init_send_data_to_autopilot_task, .next_task = &_check_mega128_values_task };
task _servo_transmit = { .name = "servo_transmit", .function = &servo_transmit, .init = 0, .next_task = &_send_data_to_autopilot_task };
task _test_ppm_task = { .name = "test_ppm_task", .function = &test_ppm_task, .init = &init_test_ppm_task, .next_task = &_servo_transmit };
task tasks_to_execute = { .name = "program_init", .function = &program_init, .init = 0, .next_task = &_test_ppm_task };