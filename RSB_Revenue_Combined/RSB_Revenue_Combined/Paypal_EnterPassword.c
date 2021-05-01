Paypal_EnterPassword()
{

	web_reg_find("Text=Found. Redirecting to", "SaveCount=loginSuccess", LAST);
	web_reg_save_param("custID_Paypal", "LB=implicit&cust=", "RB=&", "NotFound=Warning", LAST);
	web_reg_save_param("paypal_internal_eaut", "LB=Set-Cookie: jIHSLr4M5Yy4U-3CrkGq73ovwuW=", "RB=;", "NotFound=Warning", LAST);
	
	lr_start_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_12d_Paypal_03_EnterPassword"));
	
	web_add_auto_header("Content-Type", "application/x-www-form-urlencoded");
	web_add_auto_header("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9");
	
	web_submit_data("signin", 
		"Action=https://www.sandbox.paypal.com/signin?intent=checkout&ctxId=xo_ctx_{paypalPayload}&returnUri=%2Fwebapps%2Fhermes&state=%3Fflow%3D1-P%26ulReturn%3Dtrue%26useraction%3Dcommit%26token%3D{paypalPayload}&locale.x=en_US&country.x=US&flowId={paypalPayload}", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=https://www.sandbox.paypal.com/cgi-bin/webscr?cmd=_express-checkout&useraction=commit&token={paypalPayload}", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		"EncodeAtSign=YES", 
		ITEMDATA, 
		"Name=_csrf", "Value={csrfTokenString}", ENDITEM, 
		"Name=_sessionID", "Value={paypalSessionID}", ENDITEM, 
		"Name=locale.x", "Value=en_US", ENDITEM, 
		"Name=processSignin", "Value=main", ENDITEM, 
		"Name=fn_sync_data", "Value="
		"%7B%22SC_VERSION%22%3A%222.0.1%22%2C%22syncStatus%22%3A%22data%22%2C%22f%22%3A%22{paypalPayload}%22%2C%22s%22%3A%22UL_CHECKOUT_INPUT_PASSWORD%22%2C%22chk%22%3A%7B%22ts%22%3A1596563638151%2C%22eteid%22%3A%5B4062143986%2C-8445949230%2C10166125267%2C1149123879%2C6355610174%2C2828186731%2Cnull%2Cnull%5D%2C%22tts%22%3A47348%7D%2C%22dc%22%3A%22%7B%5C%22screen%5C%22%3A%7B%5C%22colorDepth%5C%22%3A24%2C%5C%22pixelDepth%5C%22%3A24%2C%5C%22height%5C%22%3A768%2C%5C%22width%5C%22%3A1366%2C%5C%22availHeigh"
		"t%5C%22%3A728%2C%5C%22availWidth%5C%22%3A1366%7D%2C%5C%22ua%5C%22%3A%5C%22Mozilla%2F5.0%20(Windows%20NT%206.1%3B%20Win64%3B%20x64)%20AppleWebKit%2F537.36%20(KHTML%2C%20like%20Gecko)"
		"%20Chrome%2F83.0.4103.97%20Safari%2F537.36%5C%22%7D%22%2C%22d%22%3A%7B%22ts1%22%3A%22Dk17%3A44748Di0%3A171Uk17%3A105Ui0%3A28Uh%3A1942Uh%3A2397%22%2C%22ts2%22%3A%22Di0%3A88403Ui0%3A141Di1%3A58Ui1%3A125Di2%3A63Ui2%3A107Di3%3A152Ui3%3A95Di4%3A137Ui4%3A84Di5%3A155Uh%3A4790%22%2C%22rDT%22%3A%2231365%2C31373%2C30770%3A10972%2C10886%2C10279%3A21257%2C21136%2C20526%3A36653%2C36509%2C35895%3A11044%2C10898%2C10278%3A11046%2C10898%2C10310%3A52033%2C51882%2C51238%3A11059%2C10900%2C10274%3A5941%2C5778%2C5142%3"
		"A41851%2C41614%2C42844%3A42161%2C41006%2C44982%3A36942%2C35967%2C35884%3A6069%2C5347%2C5157%3A46944%2C46398%2C46141%3A52004%2C51540%2C51263%3A21237%2C20803%2C20525%3A46836%2C46413%2C46141%3A10932%2C10535%2C10279%3A5793%2C5406%2C5156%3A46758%2C46388%2C46141%3A18020%2C21%22%7D%7D", ENDITEM, 
		"Name=intent", "Value=checkout", ENDITEM, 
		"Name=ads-client-context", "Value=checkout", ENDITEM, 
		"Name=flowId", "Value={paypalPayload}", ENDITEM, 
		"Name=ads-client-context-data", "Value={\"context_id\":{\"context_id\":\"{paypalPayload}\",\"channel\":0,\"flow_type\":\"checkout\"}}", ENDITEM, 
		"Name=ctxId", "Value=xo_ctx_{paypalPayload}", ENDITEM, 
		"Name=requestUrl", "Value=/signin?intent=checkout&ctxId=xo_ctx_{paypalPayload}&returnUri=%2Fwebapps%2Fhermes&state=%3Fflow%3D1-P%26ulReturn%3Dtrue%26useraction%3Dcommit%26token%3D{paypalPayload}&locale.x=en_US&country.x=US&flowId={paypalPayload}", ENDITEM, 
		"Name=forcePhonePasswordOptIn", "Value=", ENDITEM, 
		"Name=returnUri", "Value=/webapps/hermes", ENDITEM, 
		"Name=state", "Value=?flow=1-P&ulReturn=true&useraction=commit&token={paypalPayload}", ENDITEM, 
		"Name=phoneCode", "Value=US +1", ENDITEM, 
		"Name=login_email", "Value=paypal_1362585737_per@yahoo.com", ENDITEM, 
		"Name=captchaCode", "Value=", ENDITEM, 
		"Name=initialSplitLoginContext", "Value=inputEmail", ENDITEM, 
		"Name=isTpdOnboarded", "Value=", ENDITEM, 
		"Name=login_password", "Value=12345678", ENDITEM, 
		"Name=captcha", "Value=", ENDITEM, 
		"Name=splitLoginContext", "Value=inputPassword", ENDITEM, 
		"Name=otpMayflyKey", "Value={otpMayflyKey}", ENDITEM, 
		LAST);

	web_add_auto_header("Origin", 
		"https://www.sandbox.paypal.com");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("paypal-client-metadata-id", 
		"{paypalPayload}");

	web_add_auto_header("x-app-name", 
		"checkoutuinodeweb");

	web_add_auto_header("x-paypal-internal-euat", 
		"{paypal_internal_eaut}");

	web_custom_request("graphql", 
		"URL=https://www.sandbox.paypal.com/graphql/", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.sandbox.paypal.com/webapps/hermes?flow=1-P&ulReturn=true&useraction=commit&token={paypalPayload}&country.x=US&locale.x=en_US", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body=[{\"operationName\":\"InitAppQuery\",\"variables\":{\"token\":\"{paypalPayload}\"},\"query\":\"query InitAppQuery($token: String!) {\\n  checkoutSession(token: $token) {\\n    cart {\\n      cancelUrl {\\n        href\\n        __typename\\n      }\\n      amounts {\\n        total {\\n          currencyValue\\n          currencyCode\\n          __typename\\n        }\\n        __typename\\n      }\\n      __typename\\n    }\\n    merchant {\\n      merchantId\\n      __typename\\n    }"
		"\\n    __typename\\n  }\\n}\\n\"},{\"operationName\":\"MerchantLogoQuery\",\"variables\":{\"token\":\"{paypalPayload}\"},\"query\":\"query MerchantLogoQuery($token: String!) {\\n  checkoutSession(token: $token) {\\n    merchant {\\n      name\\n      logo {\\n        href\\n        __typename\\n      }\\n      __typename\\n    }\\n    __typename\\n  }\\n}\\n\"},{\"operationName\":\"HeaderQuery\",\"variables\":{\"token\":\"{paypalPayload}\"},\"query\":\"query HeaderQuery($token: String!) "
		"{\\n  checkoutSession(token: $token) {\\n    merchant {\\n      merchantId\\n      __typename\\n    }\\n    flags {\\n      hideCart\\n      hideCartDetails\\n      __typename\\n    }\\n    cart {\\n      intent\\n      total {\\n        currencyValue\\n        currencyCode\\n        currencyFormatSymbolISOCurrency\\n        __typename\\n      }\\n      items {\\n        details\\n        __typename\\n      }\\n      noteToBuyer\\n      __typename\\n    }\\n    userAction\\n    __typename\\n  }\\n"
		"}\\n\"},{\"operationName\":\"CartQuery\",\"variables\":{\"token\":\"{paypalPayload}\"},\"query\":\"query CartQuery($token: String!) {\\n  checkoutSession(token: $token) {\\n    merchant {\\n      name\\n      __typename\\n    }\\n    flags {\\n      hideCart\\n      hideCartDetails\\n      __typename\\n    }\\n    cart {\\n      cartId\\n      noteToBuyer\\n      intent\\n      total {\\n        currencyCode\\n        __typename\\n      }\\n      amounts {\\n        insurance {\\n          "
		"currencyValue\\n          currencyFormat\\n          __typename\\n        }\\n        handlingFee {\\n          currencyValue\\n          currencyFormat\\n          __typename\\n        }\\n        shipping {\\n          currencyValue\\n          currencyFormat\\n          __typename\\n        }\\n        shippingDiscount {\\n          currencyValue\\n          currencyFormat\\n          __typename\\n        }\\n        shippingAndHandling {\\n          currencyValue\\n          currencyFormat\\n "
		"         __typename\\n        }\\n        tax {\\n          currencyValue\\n          currencyFormat\\n          __typename\\n        }\\n        subtotal {\\n          currencyValue\\n          currencyFormat\\n          __typename\\n        }\\n        total {\\n          currencyValue\\n          currencyFormat\\n          __typename\\n        }\\n        discount {\\n          currencyValue\\n          currencyFormat\\n          __typename\\n        }\\n        __typename\\n      }\\n      "
		"items {\\n        name\\n        description\\n        details\\n        number\\n        unitPrice {\\n          currencyValue\\n          currencyFormat\\n          __typename\\n        }\\n        quantity\\n        total {\\n          currencyValue\\n          currencyFormat\\n          __typename\\n        }\\n        __typename\\n      }\\n      __typename\\n    }\\n    __typename\\n  }\\n}\\n\"},{\"operationName\":\"PersonalizedBannerQuery\",\"variables\":{},\"query\":\"query "
		"PersonalizedBannerQuery {\\n  user {\\n    name {\\n      givenName\\n      familyName\\n      __typename\\n    }\\n    profileImage(type: XS) {\\n      url {\\n        href\\n        __typename\\n      }\\n      __typename\\n    }\\n    __typename\\n  }\\n}\\n\"},{\"operationName\":\"AddFILink\",\"variables\":{\"token\":\"{paypalPayload}\"},\"query\":\"query AddFILink($token: String!) {\\n  checkoutSession(token: $token) {\\n    cart {\\n      billingChargePattern\\n      __typename\\n    }"
		"\\n    merchant {\\n      country\\n      isGambling\\n      __typename\\n    }\\n    checkoutSessionType\\n    __typename\\n  }\\n}\\n\"},{\"operationName\":\"GetSupportedCards\",\"variables\":{\"token\":\"{paypalPayload}\",\"country\":\"US\"},\"query\":\"query GetSupportedCards($token: String!, $country: CountryCodes!) {\\n  checkoutSession(token: $token) {\\n    allowedCardIssuers(country: $country)\\n    __typename\\n  }\\n}\\n\"},{\"operationName\":\"BillingConsentRequiredQuery\",\""
		"variables\":{\"token\":\"{paypalPayload}\"},\"query\":\"query BillingConsentRequiredQuery($token: String!) {\\n  checkoutSession(token: $token) {\\n    flags {\\n      isBillingAddressConsentRequired\\n      __typename\\n    }\\n    __typename\\n  }\\n}\\n\"},{\"operationName\":\"CancelLinkQuery\",\"variables\":{\"token\":\"{paypalPayload}\"},\"query\":\"query CancelLinkQuery($token: String!) {\\n  checkoutSession(token: $token) {\\n    merchant {\\n      name\\n      __typename\\n    }"
		"\\n    cart {\\n      cancelUrl {\\n        href\\n        __typename\\n      }\\n      amounts {\\n        total {\\n          currencyCode\\n          __typename\\n        }\\n        __typename\\n      }\\n      intent\\n      paymentId\\n      billingToken\\n      __typename\\n    }\\n    __typename\\n  }\\n}\\n\"},{\"operationName\":\"EconsentQuery\",\"variables\":{},\"query\":\"query EconsentQuery {\\n  user {\\n    eConsent\\n    __typename\\n  }\\n}\\n\"}]", 
		LAST);

	web_custom_request("graphql_2", 
		"URL=https://www.sandbox.paypal.com/graphql/", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.sandbox.paypal.com/webapps/hermes?flow=1-P&ulReturn=true&useraction=commit&token={paypalPayload}&country.x=US&locale.x=en_US", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body=[{\"operationName\":\"AddFITitle\",\"variables\":{\"token\":\"{paypalPayload}\",\"country\":\"US\"},\"query\":\"query AddFITitle($token: String!, $country: CountryCodes!) {\\n  checkoutSession(token: $token) {\\n    allowedCardIssuers(country: $country)\\n    cart {\\n      billingChargePattern\\n      __typename\\n    }\\n    merchant {\\n      country\\n      __typename\\n    }\\n    checkoutSessionType\\n    __typename\\n  }\\n}\\n\"}]", 
		LAST);

	web_custom_request("graphql_3", 
		"URL=https://www.sandbox.paypal.com/graphql/", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.sandbox.paypal.com/webapps/hermes?flow=1-P&ulReturn=true&useraction=commit&token={paypalPayload}&country.x=US&locale.x=en_US", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body=[{\"operationName\":\"ShipToQuery\",\"variables\":{\"token\":\"{paypalPayload}\"},\"query\":\"query ShipToQuery($token: String!) {\\n  checkoutSession(token: $token) {\\n    merchant {\\n      name\\n      __typename\\n    }\\n    shippingAddresses {\\n      ...ShippingAddressesFragment\\n      __typename\\n    }\\n    flags {\\n      isChangeShippingAddressAllowed\\n      hideShipping\\n      blockNonDomesticShipping\\n      isOptionallyShareAddress\\n      __typename\\n    }\\n    "
		"__typename\\n  }\\n}\\n\\nfragment ShippingAddressesFragment on CheckoutShippingAddress {\\n  isPrimary\\n  isSelected\\n  isDisabled\\n  isDefaultShipping\\n  name {\\n    fullName\\n    __typename\\n  }\\n  fullAddress\\n  addressId\\n  __typename\\n}\\n\"},{\"operationName\":\"PayWithQuery\",\"variables\":{\"token\":\"{paypalPayload}\"},\"query\":\"query PayWithQuery($token: String!) {\\n  checkoutSession(token: $token) {\\n    declinedInstruments {\\n      ...DeclinedInstrumentFragment\\n"
		"      __typename\\n    }\\n    disallowedInstruments {\\n      ...DisallowedInstrumentFragment\\n      __typename\\n    }\\n    fundingOptions(returnAllPlans: true, groupSourcesOnType: INCENTIVE) {\\n      ...FundingOptionFragment\\n      __typename\\n    }\\n    cart {\\n      intent\\n      amounts {\\n        total {\\n          currencyValue\\n          currencyFormat\\n          currencyCode\\n          currencyFormatSymbolISOCurrency\\n          __typename\\n        }\\n        __typename\\n"
		"      }\\n      category\\n      __typename\\n    }\\n    flags {\\n      allowAddresslessAddCard\\n      is3DSecureRequired\\n      isIncentivePresent\\n      isPadPreferred\\n      hasPPCreditInstallments\\n      showPPCreditOffer\\n      hideCart\\n      __typename\\n    }\\n    paymentContingencies {\\n      ...PaymentContingenciesFragment\\n      __typename\\n    }\\n    userAction\\n    checkoutSessionType\\n    __typename\\n  }\\n}\\n\\nfragment FundingOptionFragment on FundingOption {\\n  "
		"id\\n  fundingInstrument {\\n    id\\n    name\\n    nameDescription\\n    issuerProductDescription\\n    type\\n    instrumentSubType\\n    lastDigits\\n    image {\\n      url {\\n        href\\n        __typename\\n      }\\n      width\\n      height\\n      __typename\\n    }\\n    institutionImages(category: BRAND) {\\n      url {\\n        href\\n        __typename\\n      }\\n      width\\n      height\\n      __typename\\n    }\\n    isPreferred\\n    attribution\\n    "
		"...RewardsFragment\\n    creditFields {\\n      creditOffer {\\n        presentmentType\\n        product\\n        offerCategory\\n        creditOfferType\\n        financingCode\\n        crcOfferId\\n        crossCurrencyInfo {\\n          ...CrossCurrencyInfoFragment\\n          __typename\\n        }\\n        uiElements {\\n          ...CreditUIElementsFragment\\n          __typename\\n        }\\n        creditPayLater {\\n          ...CreditPayLaterFragment\\n          __typename\\n       "
		" }\\n        __typename\\n      }\\n      repaymentInstrument {\\n        id\\n        name\\n        type\\n        instrumentSubType\\n        lastDigits\\n        __typename\\n      }\\n      __typename\\n    }\\n    payerDisclaimer\\n    __typename\\n  }\\n  allPlans {\\n    id\\n    fundingSources {\\n      fundingInstrument {\\n        id\\n        name\\n        type\\n        instrumentSubType\\n        lastDigits\\n        ...InstallmentsFragment\\n        __typename\\n      }\\n      "
		"fundingMethodType\\n      delayedPaymentDate {\\n        dateShort\\n        d\\n        y\\n        M\\n        __typename\\n      }\\n      amount {\\n        currencyCode\\n        currencyValue\\n        currencyFormatSymbolISOCurrency\\n        currencyFormat\\n        __typename\\n      }\\n      groupedSources {\\n        fundingInstrument {\\n          id\\n          name\\n          type\\n          label\\n          __typename\\n        }\\n        amount {\\n          currencyValue\\n  "
		"        currencyCode\\n          currencyFormat\\n          __typename\\n        }\\n        __typename\\n      }\\n      __typename\\n    }\\n    isSelected\\n    backupFundingInstrument {\\n      id\\n      name\\n      lastDigits\\n      __typename\\n    }\\n    currencyConversion {\\n      type\\n      isReadOnly\\n      from {\\n        currencyValue\\n        currencyFormatSymbolISOCurrency\\n        currencyCode\\n        __typename\\n      }\\n      to {\\n        currencyValue\\n        "
		"currencyFormatSymbolISOCurrency\\n        currencyCode\\n        __typename\\n      }\\n      convertedAmount {\\n        currencyValue\\n        currencyFormatSymbolISOCurrency\\n        currencyCode\\n        currencyFormat\\n        __typename\\n      }\\n      rateFormatted\\n      __typename\\n    }\\n    preAuthorizationData {\\n      authType\\n      amount {\\n        currencyFormatSymbolISOCurrency\\n        __typename\\n      }\\n      __typename\\n    }\\n    __typename\\n  }\\n  "
		"__typename\\n}\\n\\nfragment InstallmentsFragment on FundingInstrument {\\n  installments {\\n    term\\n    monthlyPayment {\\n      currencyCode\\n      currencyFormat\\n      currencyFormatSymbolISOCurrency\\n      currencySymbol\\n      currencyValue\\n      __typename\\n    }\\n    totalCost {\\n      currencyCode\\n      currencyFormat\\n      currencyFormatSymbolISOCurrency\\n      currencySymbol\\n      currencyValue\\n      __typename\\n    }\\n    discount {\\n      amount {\\n        "
		"currencyCode\\n        currencyFormat\\n        currencyFormatSymbolISOCurrency\\n        currencySymbol\\n        currencyValue\\n        __typename\\n      }\\n      percentage\\n      __typename\\n    }\\n    __typename\\n  }\\n  __typename\\n}\\n\\nfragment RewardsFragment on FundingInstrument {\\n  rewards {\\n    id\\n    relatedCardId\\n    rewardType\\n    availableRewards {\\n      value\\n      denominationTypeDescription\\n      monetaryValue {\\n        currencySymbol\\n        "
		"currencyValue\\n        currencyCode\\n        currencyFormat\\n        __typename\\n      }\\n      __typename\\n    }\\n    conversionMetadata {\\n      conversionFactor\\n      decimalPrecision {\\n        toAmount\\n        toRewards\\n        __typename\\n      }\\n      roundingMode {\\n        toAmount\\n        toRewards\\n        __typename\\n      }\\n      __typename\\n    }\\n    constraints {\\n      minimumSpend {\\n        currencySymbol\\n        currencyValue\\n        "
		"currencyCode\\n        __typename\\n      }\\n      maximumSpend {\\n        currencySymbol\\n        currencyValue\\n        currencyCode\\n        __typename\\n      }\\n      maximumUsable {\\n        currencySymbol\\n        currencyValue\\n        currencyCode\\n        __typename\\n      }\\n      __typename\\n    }\\n    balance {\\n      targetCurrencyCode\\n      isConvertable\\n      __typename\\n    }\\n    issuer {\\n      name\\n      instrumentType\\n      issuerProductDescription\\n"
		"      __typename\\n    }\\n    redemptionType\\n    termsUrl\\n    image(size: S) {\\n      url {\\n        href\\n        __typename\\n      }\\n      width\\n      height\\n      __typename\\n    }\\n    __typename\\n  }\\n  __typename\\n}\\n\\nfragment CreditUIElementsFragment on CreditUIElements {\\n  creditOffer {\\n    sectionHeadlineText\\n    headlineText\\n    descriptorText\\n    continueButtonText\\n    __typename\\n  }\\n  creditOnlyFI {\\n    descriptorText\\n    headlineText\\n    "
		"__typename\\n  }\\n  creditFI {\\n    headlineText\\n    descriptorText\\n    payButtonText\\n    continueButtonText\\n    __typename\\n  }\\n  fiHighlightText\\n  logoAltText\\n  logo {\\n    href\\n    __typename\\n  }\\n  __typename\\n}\\n\\nfragment CreditPayLaterFragment on CreditPayLater {\\n  totalCost {\\n    currencyFormat\\n    __typename\\n  }\\n  totalFee {\\n    currencyFormat\\n    __typename\\n  }\\n  installmentsSchedule {\\n    principal {\\n      currencyFormat\\n      "
		"__typename\\n    }\\n    paymentType\\n    paymentNumber\\n    interest {\\n      currencyFormat\\n      __typename\\n    }\\n    consumerFee {\\n      currencyFormat\\n      __typename\\n    }\\n    paymentDate\\n    totalPayment {\\n      currencyCode\\n      currencyFormat\\n      currencyFormatSymbolISOCurrency\\n      currencyValue\\n      __typename\\n    }\\n    __typename\\n  }\\n  noDownPaymentAmt {\\n    currencyCode\\n    currencyFormat\\n    currencyFormatSymbolISOCurrency\\n    "
		"currencyValue\\n    __typename\\n  }\\n  __typename\\n}\\n\\nfragment CrossCurrencyInfoFragment on CreditCrossCurrency {\\n  currencyConversionRate\\n  fromCurrencyCode\\n  fromFormattedCurrencyConversionValue\\n  fxAuditTrailId\\n  toCurrencyCode\\n  toFormattedCurrencyConversionValue\\n  rateDescriptor\\n  learnMoreText\\n  learnMoreLink\\n  currencyConversionDescriptor\\n  __typename\\n}\\n\\nfragment DeclinedInstrumentFragment on DeclinedInstrument {\\n  id\\n  declineType\\n  "
		"normalizedProcessorResponse\\n  lastDigits\\n  type\\n  name\\n  issuerProductDescription\\n  partialFpan\\n  image {\\n    url {\\n      href\\n      __typename\\n    }\\n    width\\n    height\\n    __typename\\n  }\\n  __typename\\n}\\n\\nfragment DisallowedInstrumentFragment on DisallowedInstrument {\\n  id\\n  reason\\n  lastDigits\\n  isPreferred\\n  type\\n  name\\n  label\\n  formattedType\\n  instrumentSubType\\n  image {\\n    url {\\n      href\\n      __typename\\n    }\\n    width\\n "
		"   height\\n    __typename\\n  }\\n  __typename\\n}\\n\\nfragment PaymentContingenciesFragment on PaymentContingencies {\\n  confirmCreditCardCvvData {\\n    ...ConfirmCreditCardCvvFields\\n    __typename\\n  }\\n  sepaMandateAcceptanceNeeded {\\n    ...SepaMandateAcceptanceNeededFragment\\n    __typename\\n  }\\n  threeDomainSecure {\\n    ...ThreeDomainSecureFields\\n    __typename\\n  }\\n  needConsentForBankAccountInfoRetrieval {\\n    encryptedId\\n    __typename\\n  }\\n  "
		"needRealTimeBalanceForBankAccount {\\n    encryptedId\\n    __typename\\n  }\\n  __typename\\n}\\n\\nfragment ConfirmCreditCardCvvFields on ConfirmCreditCardCvvContingency {\\n  encryptedId\\n  lastFourDigits\\n  type\\n  __typename\\n}\\n\\nfragment ThreeDomainSecureFields on ThreeDomainSecureContingency {\\n  redirectUrl {\\n    href\\n    __typename\\n  }\\n  status\\n  method\\n  parameter\\n  encryptedId\\n  experience\\n  requestParams {\\n    key\\n    value\\n    __typename\\n  }\\n  "
		"__typename\\n}\\n\\nfragment SepaMandateAcceptanceNeededFragment on BankAccount {\\n  id\\n  type\\n  accountNumber\\n  accountNumberShort\\n  bankIdentifierCode\\n  currencyCode\\n  beneficiaries {\\n    fullName\\n    __typename\\n  }\\n  billingAddress {\\n    city\\n    country\\n    state\\n    fullAddress\\n    __typename\\n  }\\n  issuer {\\n    name\\n    __typename\\n  }\\n  creditor {\\n    id\\n    name\\n    address {\\n      fullAddress\\n      __typename\\n    }\\n    __typename\\n  "
		"}\\n  __typename\\n}\\n\"},{\"operationName\":\"CreditInstallmentOfferQuery\",\"variables\":{\"areCookiesDisabled\":false,\"isIframe\":false,\"token\":\"{paypalPayload}\"},\"query\":\"query CreditInstallmentOfferQuery($token: String!, $areCookiesDisabled: Boolean, $isIframe: Boolean) {\\n  checkoutSession(token: $token) {\\n    cart {\\n      total {\\n        currencyCode\\n        currencyValue\\n        __typename\\n      }\\n      __typename\\n    }\\n    buyer {\\n      userId\\n      "
		"__typename\\n    }\\n    merchant {\\n      merchantId\\n      __typename\\n    }\\n    fundingOptions {\\n      fundingInstrument {\\n        name\\n        type\\n        __typename\\n      }\\n      __typename\\n    }\\n    creditAsFIOffers(areCookiesDisabled: $areCookiesDisabled, isIframe: $isIframe) {\\n      ...CreditOfferAsFIFragment\\n      __typename\\n    }\\n    __typename\\n  }\\n}\\n\\nfragment CreditOfferAsFIFragment on CreditAsFIOffer {\\n  referenceId\\n  rank\\n  "
		"presentmentType\\n  product\\n  offerCategory\\n  crcOfferId\\n  crossCurrencyInfo {\\n    ...CrossCurrencyInfoFragment\\n    __typename\\n  }\\n  uiElements {\\n    ...CreditUIElementsFragment\\n    __typename\\n  }\\n  creditPayLater {\\n    ...CreditPayLaterFragment\\n    __typename\\n  }\\n  trackingDetails {\\n    impressionUrl {\\n      href\\n      __typename\\n    }\\n    clickUrl {\\n      href\\n      __typename\\n    }\\n    dismissUrl {\\n      href\\n      __typename\\n    }\\n    "
		"__typename\\n  }\\n  __typename\\n}\\n\\nfragment CrossCurrencyInfoFragment on CreditCrossCurrency {\\n  currencyConversionRate\\n  fromCurrencyCode\\n  fromFormattedCurrencyConversionValue\\n  fxAuditTrailId\\n  toCurrencyCode\\n  toFormattedCurrencyConversionValue\\n  rateDescriptor\\n  learnMoreText\\n  learnMoreLink\\n  currencyConversionDescriptor\\n  __typename\\n}\\n\\nfragment CreditUIElementsFragment on CreditUIElements {\\n  creditOffer {\\n    sectionHeadlineText\\n    headlineText\\n  "
		"  descriptorText\\n    continueButtonText\\n    __typename\\n  }\\n  creditOnlyFI {\\n    descriptorText\\n    headlineText\\n    __typename\\n  }\\n  creditFI {\\n    headlineText\\n    descriptorText\\n    payButtonText\\n    continueButtonText\\n    __typename\\n  }\\n  fiHighlightText\\n  logoAltText\\n  logo {\\n    href\\n    __typename\\n  }\\n  __typename\\n}\\n\\nfragment CreditPayLaterFragment on CreditPayLater {\\n  totalCost {\\n    currencyFormat\\n    __typename\\n  }\\n  totalFee "
		"{\\n    currencyFormat\\n    __typename\\n  }\\n  installmentsSchedule {\\n    principal {\\n      currencyFormat\\n      __typename\\n    }\\n    paymentType\\n    paymentNumber\\n    interest {\\n      currencyFormat\\n      __typename\\n    }\\n    consumerFee {\\n      currencyFormat\\n      __typename\\n    }\\n    paymentDate\\n    totalPayment {\\n      currencyCode\\n      currencyFormat\\n      currencyFormatSymbolISOCurrency\\n      currencyValue\\n      __typename\\n    }\\n    "
		"__typename\\n  }\\n  noDownPaymentAmt {\\n    currencyCode\\n    currencyFormat\\n    currencyFormatSymbolISOCurrency\\n    currencyValue\\n    __typename\\n  }\\n  __typename\\n}\\n\"},{\"operationName\":\"BillingAgreementQuery\",\"variables\":{\"token\":\"{paypalPayload}\"},\"query\":\"query BillingAgreementQuery($token: String!) {\\n  checkoutSession(token: $token) {\\n    merchant {\\n      name\\n      merchantId\\n      country\\n      __typename\\n    }\\n    cart {\\n      "
		"billingType\\n      consentCode\\n      __typename\\n    }\\n    userAction\\n    checkoutSessionType\\n    __typename\\n  }\\n}\\n\"},{\"operationName\":\"CreditOfferQuery\",\"variables\":{\"token\":\"{paypalPayload}\"},\"query\":\"query CreditOfferQuery($token: String!) {\\n  checkoutSession(token: $token) {\\n    cart {\\n      intent\\n      __typename\\n    }\\n    fundingOptions(returnAllPlans: true, groupSourcesOnType: INCENTIVE) {\\n      ...FundingOptionFragment\\n      __typename\\n"
		"    }\\n    buyer {\\n      userId\\n      __typename\\n    }\\n    creditPPCOffers {\\n      ...CreditOfferFragment\\n      __typename\\n    }\\n    flags {\\n      showPPCreditOffer\\n      hasPPCreditInstallments\\n      hideCart\\n      __typename\\n    }\\n    __typename\\n  }\\n}\\n\\nfragment FundingOptionFragment on FundingOption {\\n  id\\n  fundingInstrument {\\n    id\\n    name\\n    nameDescription\\n    issuerProductDescription\\n    type\\n    instrumentSubType\\n    lastDigits\\n  "
		"  image {\\n      url {\\n        href\\n        __typename\\n      }\\n      width\\n      height\\n      __typename\\n    }\\n    institutionImages(category: BRAND) {\\n      url {\\n        href\\n        __typename\\n      }\\n      width\\n      height\\n      __typename\\n    }\\n    isPreferred\\n    attribution\\n    ...RewardsFragment\\n    creditFields {\\n      creditOffer {\\n        presentmentType\\n        product\\n        offerCategory\\n        creditOfferType\\n        "
		"financingCode\\n        crcOfferId\\n        crossCurrencyInfo {\\n          ...CrossCurrencyInfoFragment\\n          __typename\\n        }\\n        uiElements {\\n          ...CreditUIElementsFragment\\n          __typename\\n        }\\n        creditPayLater {\\n          ...CreditPayLaterFragment\\n          __typename\\n        }\\n        __typename\\n      }\\n      repaymentInstrument {\\n        id\\n        name\\n        type\\n        instrumentSubType\\n        lastDigits\\n        "
		"__typename\\n      }\\n      __typename\\n    }\\n    payerDisclaimer\\n    __typename\\n  }\\n  allPlans {\\n    id\\n    fundingSources {\\n      fundingInstrument {\\n        id\\n        name\\n        type\\n        instrumentSubType\\n        lastDigits\\n        ...InstallmentsFragment\\n        __typename\\n      }\\n      fundingMethodType\\n      delayedPaymentDate {\\n        dateShort\\n        d\\n        y\\n        M\\n        __typename\\n      }\\n      amount {\\n        "
		"currencyCode\\n        currencyValue\\n        currencyFormatSymbolISOCurrency\\n        currencyFormat\\n        __typename\\n      }\\n      groupedSources {\\n        fundingInstrument {\\n          id\\n          name\\n          type\\n          label\\n          __typename\\n        }\\n        amount {\\n          currencyValue\\n          currencyCode\\n          currencyFormat\\n          __typename\\n        }\\n        __typename\\n      }\\n      __typename\\n    }\\n    isSelected\\n "
		"   backupFundingInstrument {\\n      id\\n      name\\n      lastDigits\\n      __typename\\n    }\\n    currencyConversion {\\n      type\\n      isReadOnly\\n      from {\\n        currencyValue\\n        currencyFormatSymbolISOCurrency\\n        currencyCode\\n        __typename\\n      }\\n      to {\\n        currencyValue\\n        currencyFormatSymbolISOCurrency\\n        currencyCode\\n        __typename\\n      }\\n      convertedAmount {\\n        currencyValue\\n        "
		"currencyFormatSymbolISOCurrency\\n        currencyCode\\n        currencyFormat\\n        __typename\\n      }\\n      rateFormatted\\n      __typename\\n    }\\n    preAuthorizationData {\\n      authType\\n      amount {\\n        currencyFormatSymbolISOCurrency\\n        __typename\\n      }\\n      __typename\\n    }\\n    __typename\\n  }\\n  __typename\\n}\\n\\nfragment InstallmentsFragment on FundingInstrument {\\n  installments {\\n    term\\n    monthlyPayment {\\n      currencyCode\\n   "
		"   currencyFormat\\n      currencyFormatSymbolISOCurrency\\n      currencySymbol\\n      currencyValue\\n      __typename\\n    }\\n    totalCost {\\n      currencyCode\\n      currencyFormat\\n      currencyFormatSymbolISOCurrency\\n      currencySymbol\\n      currencyValue\\n      __typename\\n    }\\n    discount {\\n      amount {\\n        currencyCode\\n        currencyFormat\\n        currencyFormatSymbolISOCurrency\\n        currencySymbol\\n        currencyValue\\n        __typename\\n  "
		"    }\\n      percentage\\n      __typename\\n    }\\n    __typename\\n  }\\n  __typename\\n}\\n\\nfragment RewardsFragment on FundingInstrument {\\n  rewards {\\n    id\\n    relatedCardId\\n    rewardType\\n    availableRewards {\\n      value\\n      denominationTypeDescription\\n      monetaryValue {\\n        currencySymbol\\n        currencyValue\\n        currencyCode\\n        currencyFormat\\n        __typename\\n      }\\n      __typename\\n    }\\n    conversionMetadata {\\n      "
		"conversionFactor\\n      decimalPrecision {\\n        toAmount\\n        toRewards\\n        __typename\\n      }\\n      roundingMode {\\n        toAmount\\n        toRewards\\n        __typename\\n      }\\n      __typename\\n    }\\n    constraints {\\n      minimumSpend {\\n        currencySymbol\\n        currencyValue\\n        currencyCode\\n        __typename\\n      }\\n      maximumSpend {\\n        currencySymbol\\n        currencyValue\\n        currencyCode\\n        __typename\\n    "
		"  }\\n      maximumUsable {\\n        currencySymbol\\n        currencyValue\\n        currencyCode\\n        __typename\\n      }\\n      __typename\\n    }\\n    balance {\\n      targetCurrencyCode\\n      isConvertable\\n      __typename\\n    }\\n    issuer {\\n      name\\n      instrumentType\\n      issuerProductDescription\\n      __typename\\n    }\\n    redemptionType\\n    termsUrl\\n    image(size: S) {\\n      url {\\n        href\\n        __typename\\n      }\\n      width\\n      "
		"height\\n      __typename\\n    }\\n    __typename\\n  }\\n  __typename\\n}\\n\\nfragment CreditUIElementsFragment on CreditUIElements {\\n  creditOffer {\\n    sectionHeadlineText\\n    headlineText\\n    descriptorText\\n    continueButtonText\\n    __typename\\n  }\\n  creditOnlyFI {\\n    descriptorText\\n    headlineText\\n    __typename\\n  }\\n  creditFI {\\n    headlineText\\n    descriptorText\\n    payButtonText\\n    continueButtonText\\n    __typename\\n  }\\n  fiHighlightText\\n  "
		"logoAltText\\n  logo {\\n    href\\n    __typename\\n  }\\n  __typename\\n}\\n\\nfragment CreditPayLaterFragment on CreditPayLater {\\n  totalCost {\\n    currencyFormat\\n    __typename\\n  }\\n  totalFee {\\n    currencyFormat\\n    __typename\\n  }\\n  installmentsSchedule {\\n    principal {\\n      currencyFormat\\n      __typename\\n    }\\n    paymentType\\n    paymentNumber\\n    interest {\\n      currencyFormat\\n      __typename\\n    }\\n    consumerFee {\\n      currencyFormat\\n     "
		" __typename\\n    }\\n    paymentDate\\n    totalPayment {\\n      currencyCode\\n      currencyFormat\\n      currencyFormatSymbolISOCurrency\\n      currencyValue\\n      __typename\\n    }\\n    __typename\\n  }\\n  noDownPaymentAmt {\\n    currencyCode\\n    currencyFormat\\n    currencyFormatSymbolISOCurrency\\n    currencyValue\\n    __typename\\n  }\\n  __typename\\n}\\n\\nfragment CrossCurrencyInfoFragment on CreditCrossCurrency {\\n  currencyConversionRate\\n  fromCurrencyCode\\n  "
		"fromFormattedCurrencyConversionValue\\n  fxAuditTrailId\\n  toCurrencyCode\\n  toFormattedCurrencyConversionValue\\n  rateDescriptor\\n  learnMoreText\\n  learnMoreLink\\n  currencyConversionDescriptor\\n  __typename\\n}\\n\\nfragment CreditOfferFragment on CreditPPCOffer {\\n  content\\n  rank\\n  referenceId\\n  trackingDetails {\\n    impressionUrl {\\n      href\\n      __typename\\n    }\\n    __typename\\n  }\\n  __typename\\n}\\n\"},{\"operationName\":\"GACQuery\",\"variables\":{\"token\":"
		"\"{paypalPayload}\"},\"query\":\"query GACQuery($token: String!) {\\n  checkoutSession(token: $token) {\\n    suggestedDonation {\\n      ...SuggestedDonationFragment\\n      __typename\\n    }\\n    __typename\\n  }\\n}\\n\\nfragment SuggestedDonationFragment on SuggestedDonation {\\n  content {\\n    nonprofitId\\n    nonprofitName\\n    nonprofitPayPalId\\n    nonprofitLogoUrl {\\n      href\\n      __typename\\n    }\\n    modelId\\n    donateMessage\\n    promoMessage\\n    "
		"legalDisclaimerHeaderMessage\\n    legalDisclaimerBodyMessage\\n    __typename\\n  }\\n  trackingDetails {\\n    impressionUrl {\\n      href\\n      __typename\\n    }\\n    clickUrl {\\n      href\\n      __typename\\n    }\\n    __typename\\n  }\\n  __typename\\n}\\n\"},{\"operationName\":\"DisclaimerQuery\",\"variables\":{\"token\":\"{paypalPayload}\"},\"query\":\"query DisclaimerQuery($token: String!) {\\n  checkoutSession(token: $token) {\\n    merchant {\\n      descriptor\\n      "
		"name\\n      __typename\\n    }\\n    cart {\\n      intent\\n      __typename\\n    }\\n    userAction\\n    checkoutSessionType\\n    __typename\\n  }\\n}\\n\"}]", 
		EXTRARES, 
		"Url=https://www.paypalobjects.com/checkoutweb/release/hermione/css/Button~493df0b3.c4a01aa4.css", "Referer=https://www.sandbox.paypal.com/webapps/hermes?flow=1-P&ulReturn=true&useraction=commit&token={paypalPayload}&country.x=US&locale.x=en_US", ENDITEM, 
		"Url=https://www.paypalobjects.com/checkoutweb/release/hermione/js/PayWith~21833f8f.298d4fd0.js", "Referer=https://www.sandbox.paypal.com/webapps/hermes?flow=1-P&ulReturn=true&useraction=commit&token={paypalPayload}&country.x=US&locale.x=en_US", ENDITEM, 
		"Url=https://www.paypalobjects.com/checkoutweb/release/hermione/js/vendors~CreditOfferAsFi~4134d62c.40d990e3.js", "Referer=https://www.sandbox.paypal.com/webapps/hermes?flow=1-P&ulReturn=true&useraction=commit&token={paypalPayload}&country.x=US&locale.x=en_US", ENDITEM, 
		"Url=https://www.paypalobjects.com/checkoutweb/release/hermione/js/CreditOfferAsFi~7448b103.ad5f17ea.js", "Referer=https://www.sandbox.paypal.com/webapps/hermes?flow=1-P&ulReturn=true&useraction=commit&token={paypalPayload}&country.x=US&locale.x=en_US", ENDITEM, 
		"Url=https://www.paypalobjects.com/checkoutweb/release/hermione/js/Button~493df0b3.72cb6c61.js", "Referer=https://www.sandbox.paypal.com/webapps/hermes?flow=1-P&ulReturn=true&useraction=commit&token={paypalPayload}&country.x=US&locale.x=en_US", ENDITEM, 
		"Url=https://www.paypalobjects.com/checkoutweb/release/hermione/js/Disclaimer~21833f8f.f5091453.js", "Referer=https://www.sandbox.paypal.com/webapps/hermes?flow=1-P&ulReturn=true&useraction=commit&token={paypalPayload}&country.x=US&locale.x=en_US", ENDITEM, 
		LAST);

	web_revert_auto_header("Origin");

	web_revert_auto_header("paypal-client-metadata-id");

	web_revert_auto_header("x-app-name");

	web_revert_auto_header("x-paypal-internal-euat");
	
	web_add_header("paypal-client-metadata-id", 
		"{paypalPayload}");

	web_add_header("x-app-name", 
		"checkoutuinodeweb");

	web_add_header("x-paypal-internal-euat", 
		"{paypal_internal_eaut}");

	web_custom_request("graphql_4", 
		"URL=https://www.sandbox.paypal.com/graphql/", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.sandbox.paypal.com/webapps/hermes?flow=1-P&ulReturn=true&useraction=commit&token={paypalPayload}&country.x=US&locale.x=en_US", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		"EncType=application/json", 
		"Body=[{\"operationName\":\"PayPalConfirmedCharityQuery\",\"variables\":{\"token\":\"{paypalPayload}\"},\"query\":\"query PayPalConfirmedCharityQuery($token: String!) {\\n  checkoutSession(token: $token) {\\n    cart {\\n      category\\n      __typename\\n    }\\n    merchant {\\n      isPaypalConfirmedCharity\\n      __typename\\n    }\\n    __typename\\n  }\\n}\\n\"}]", 
		EXTRARES, 
		LAST);
	
	if(atoi(lr_eval_string("{loginSuccess}"))<=0)
	{
		lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_12d_Paypal_03_EnterPassword"), LR_FAIL);		
		lr_exit(LR_EXIT_ITERATION_AND_CONTINUE, LR_AUTO);		
	}
	
	lr_end_transaction(lr_eval_string("RSB_Revenue_{RandTripType}_12d_Paypal_03_EnterPassword"), LR_AUTO);

	return 0;
}
