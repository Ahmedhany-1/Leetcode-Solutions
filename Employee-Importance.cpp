class Solution {
    unordered_map<int, Employee*> id_to_emp;

    // return sum of all the nodes uder this node
	// Why no visited array? No need for visited array in DAG, as no cycles :)

	int dfs(int id) {
		Employee *emp = id_to_emp[id];

		int result = emp->importance;
		for (auto &subEmp : emp->subordinates)
			result += dfs(subEmp);

		return result;
	}

public:
    int getImportance(vector<Employee*> employees, int id) {
        for (auto &emp : employees)
			id_to_emp[emp->id] = emp;

		return dfs(id);
    }
};