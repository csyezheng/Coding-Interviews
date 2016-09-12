#ifndef ASSIGNMENTOPERATOR_H
#define ASSIGNMENTOPERATOR_H

class CMyString
{
public:
	CMyString(char *pData = nullptr);
	CMyString(const CMyString &str);
	CMyString &operator= (const CMyString &str);
	~CMyString(void);
private:
	char *m_pData;
};

CMyString::CMyString(char *pData) : m_pData(new char(*pData)) { }

CMyString::CMyString(const CMyString &str) : m_pData(new char[strlen(str.m_pData) + 1]) { }

CMyString::~CMyString(void)
{
	delete m_pData;
}
CMyString &CMyString::operator= (const CMyString &str)
{
	char *pnew = new char[std::strlen(str.m_pData) + 1];
	delete[]m_pData;
	m_pData = pnew;
	pnew = nullptr;
}



#endif