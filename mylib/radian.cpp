// 弧度法から度数法への変換
ld radToDeg(ld rad)
{
	return 180 * rad / M_PI;
}

// 点(baseX, baseY)を原点とした場合の原点と点(x, y)を繋いだ直線のX軸からの角度
// 戻り: [0 ~ 2π]
ld radFromXAxis(ll x, ll y, ll baseX, ll baseY)
{
	ll xx = x - baseX;
	ll yy = y - baseY;

	ld ret = atan2l(yy, xx);
	if (ret < 0)
		ret += M_PI * 2;

	return ret;
}