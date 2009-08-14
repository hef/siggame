#ifndef UTILS_H
#define UTILS_H

class Utils
{
	public:
		Utils();
		~Utils();
		unsigned int sumUp( const unsigned int n ) const;

	private:
		// Make calls to sumUp from all other types cause a compile-time error
		template< class t >
		unsigned int sumUp( const t ) const { return 0; }
};

#endif /* Utils_H */