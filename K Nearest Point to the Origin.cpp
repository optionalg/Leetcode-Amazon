struct Point{
	double x, y;
	Point(double _x, double _y) : x(_x), y(_y){}
	double dist2() const { return x * x + y * y; }
	bool operator<(const Point &p) const { return dist2() < p.dist2(); }
};
vector<Point> getKNearestPoint(vector<Point> &points, int k){
	priority_queue<Point> pq;
	for(int i = 0; i < points.size(); ++i){
		if(pq.size() < k)
			pq.push(points[i]);
		else if(pq.top().dist2() > points[i].dist2()){
			pq.pop();
			pq.push(points[i]);
		}
	}
	vector<Point> res;
	while(!pq.empty()) res.push_back(pq.top()), pq.pop();
	return res;
}
