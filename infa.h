typedef struct {
	char name[20];
	char color[20];
	int cost;
} tvr;
void create(tvr **arr, int *count);
void load(tvr **arr, int *count);
void save(tvr *arr, int count);
void add(tvr **arr, int *count);
void del(tvr *arr, int *count);
void edit(tvr *arr, int count);
void search(tvr *arr, int count);
void show(tvr *arr, int count);
