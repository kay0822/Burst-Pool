#ifndef PAYPAL_PAYMENT_HPP
#define PAYPAL_PAYMENT_HPP

#include <string> 


class PayPal_Payment {
	public:
		PayPal_Payment( std::string paymentID, std::string approval_URL, std::string execute_URL );

		std::string paymentID;
		std::string approval_URL;
		std::string execute_URL;
};

#endif
