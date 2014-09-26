#ifndef CCLIENT_H
#define CCLIENT_H


namespace GPS_Server
{

enum ClientType { TCP, UDP, MCAST, UNKNOWN };

class cClient
{
	public:

		/* Default constructor */
		cClient();
		cClient(ClientType type);

		/* Default destructor */
		virtual ~cClient();

	protected:
	private:
		ClientType m_Type;
};

}

#endif // CCLIENT_H
