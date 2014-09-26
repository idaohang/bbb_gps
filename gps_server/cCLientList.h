#ifndef CCLIENTLIST_H
#define CCLIENTLIST_H

#include <deque>
#include "cClient.h"

namespace GPS_Server
{

class cCLientList
{
	public:
		/** Default constructor */
		cCLientList();
		/** Default destructor */
		virtual ~cCLientList();

		int AddClient(cClient *);
		int DelClient(cClient *);

	protected:
	private:

		bool m_Lock;
		std::deque<cClient *> m_Clients;
};

}
#endif // CCLIENTLIST_H
