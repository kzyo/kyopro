/*
  startNum ~ endNumからselectNum個選んだ組み合わせを返す
*/
void _combination(vector<int> tmp, vector<vector<int>> *combinations, int selectNum, int startNum, int endNum);

vector<vector<int>> combination(int selectNum, int startNum, int endNum)
{
	vector<vector<int>> combinations;
	_combination(vector<int>{}, &combinations, selectNum, startNum, endNum);
	return combinations;
}

void _combination(vector<int> tmp, vector<vector<int>> *combinations, int selectNum, int startNum, int endNum)
{

	if (tmp.size() == selectNum)
	{
		(*combinations).push_back(tmp);
		return;
	}

	int start = startNum;
	if (tmp.size() > 0)
		start = tmp.back() + 1;

	int idx = tmp.size();
	tmp.resize(tmp.size() + 1);
	for (int num = start; num <= endNum; num++)
	{
		tmp[idx] = num;
		_combination(tmp, combinations, selectNum, startNum, endNum);
	}
}