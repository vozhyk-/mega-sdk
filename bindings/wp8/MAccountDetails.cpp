/**
* @file MAccountDetails.cpp
* @brief Get details about a MEGA account.
*
* (c) 2013-2014 by Mega Limited, Auckland, New Zealand
*
* This file is part of the MEGA SDK - Client Access Engine.
*
* Applications using the MEGA API must present a valid application key
* and comply with the the rules set forth in the Terms of Service.
*
* The MEGA SDK is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* @copyright Simplified (2-clause) BSD License.
*
* You should have received a copy of the license along with this
* program.
*/

#include "MAccountDetails.h"

using namespace mega;
using namespace Platform;

MAccountDetails::MAccountDetails(MegaAccountDetails *accountDetails, bool cMemoryOwn)
{
	this->accountDetails = accountDetails;
	this->cMemoryOwn;
}

MAccountDetails::~MAccountDetails()
{
	if (cMemoryOwn)
		delete accountDetails;
}

MegaAccountDetails* MAccountDetails::getCPtr()
{
	return accountDetails;
}

MAccountType MAccountDetails::getProLevel()
{
	return (MAccountType)(accountDetails ? accountDetails->getProLevel() : 0);
}

int64 MAccountDetails::getProExpiration()
{
	return accountDetails ? accountDetails->getProExpiration() : 0;
}

MSubscriptionStatus MAccountDetails::getSubscriptionStatus()
{
	return (MSubscriptionStatus)(accountDetails ? accountDetails->getSubscriptionStatus() : 0);
}

int64 MAccountDetails::getSubscriptionRenewTime()
{
	return accountDetails ? accountDetails->getSubscriptionRenewTime() : 0;
}

String^ MAccountDetails::getSubscriptionMethod()
{
	if (!accountDetails) return nullptr;

	std::string utf16subscriptionMethod;
	const char *utf8subscriptionMethod = accountDetails->getSubscriptionMethod();
	MegaApi::utf8ToUtf16(utf8subscriptionMethod, &utf16subscriptionMethod);

	return utf8subscriptionMethod ? ref new String((wchar_t *)utf16subscriptionMethod.data()) : nullptr;
}

String^ MAccountDetails::getSubscriptionCycle()
{
	if (!accountDetails) return nullptr;

	std::string utf16subscriptionCycle;
	const char *utf8subscriptionCycle = accountDetails->getSubscriptionCycle();
	MegaApi::utf8ToUtf16(utf8subscriptionCycle, &utf16subscriptionCycle);

	return utf8subscriptionCycle ? ref new String((wchar_t *)utf16subscriptionCycle.data()) : nullptr;
}

uint64 MAccountDetails::getStorageMax()
{
	return accountDetails ? accountDetails->getStorageMax() : 0;
}

uint64 MAccountDetails::getStorageUsed() 
{
	return accountDetails ? accountDetails->getStorageUsed() : 0;
}

uint64 MAccountDetails::getTransferMax()
{
	return accountDetails ? accountDetails->getTransferMax() : 0;
}

uint64 MAccountDetails::getTransferOwnUsed()
{
	return accountDetails ? accountDetails->getTransferOwnUsed() : 0;
}

int MAccountDetails::getNumUsageItems()
{
	return accountDetails ? accountDetails->getNumUsageItems() : 0;
}

uint64 MAccountDetails::getStorageUsed(uint64 handle)
{
	return accountDetails ? accountDetails->getStorageUsed(handle) : 0;
}

uint64 MAccountDetails::getNumFiles(uint64 handle)
{
	return accountDetails ? accountDetails->getNumFiles(handle) : 0;
}

uint64 MAccountDetails::getNumFolders(uint64 handle)
{
	return accountDetails ? accountDetails->getNumFolders(handle) : 0;
}
