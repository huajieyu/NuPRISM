#ifndef T_ARRAY3D_H
#define T_ARRAY3D_H

template <class T>
class TArray3D
{
public:
	TArray3D(int x, int y, int z, int c = 0)
   :m_x(x),
    m_y(y),
	m_z(z),
	m_arr(new T**[m_x])
    {
		for (int i(0); i < m_x; ++i)
		{
			m_arr[i] = new T*[m_y];
			for (int j(0); j < m_y; ++j)
			{
				m_arr[i][j] = new T[m_z];
				for (int k(0); k < m_z; ++k)
					m_arr[i][j][k] = c;
			}
		}
	};

	~TArray3D()
	{
		for (int i(0); i < m_x; ++i)
		{
			for (int j(0); j < m_y; ++j)
				delete [] m_arr[i][j];

			delete [] m_arr[i];
		}

		delete [] m_arr;
	};

	T& operator()(int i, int j, int k)
	{
		return m_arr[i][j][k];
	};

	const T& operator()(int i, int j, int k) const
	{
		return m_arr[i][j][k];
	};

	int get_x() const
	{
		return m_x;
	};

	int get_y() const
	{
		return m_y;
	};

	int get_z() const
	{
		return m_z;
	};


private:
	const int m_x;
	const int m_y;
	const int m_z;
	T*** m_arr;
};

#endif
