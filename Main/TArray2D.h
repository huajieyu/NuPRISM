#ifndef T_ARRAY2D_H
#define T_ARRAY2D_H

template <class T>
class TArray2D
{
public:
	TArray2D(int x, int y, int c = 0)
   :m_x(x),
    m_y(y),
	m_arr(new T*[m_x])
    {
		for (int i(0); i < m_x; ++i)
		{
			m_arr[i] = new T[m_y];

			for (int j(0); j < m_y; ++j)
				m_arr[i][j] = c;
		}
	};

	~TArray2D()
	{
		for (int i(0); i < m_x; ++i)
		{
			delete [] m_arr[i];
		}

		delete [] m_arr;
	};

	T& operator()(int i, int j)
	{
		return m_arr[i][j];
	};

	const T& operator()(int i, int j) const
	{
		return m_arr[i][j];
	};

	int get_x() const
	{
		return m_x;
	};

	int get_y() const
	{
		return m_y;
	};


private:
	const int m_x;
	const int m_y;
	T** m_arr;
};

#endif
