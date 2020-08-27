a = '''UserLoginName
CryptType
Pswd
VendorName
AppName
AppVer
TransRefGUID
TransType
TransExeDate
HoldingTypeCode
Purpose
LineOfBusiness
ProductType
CarrierCode
PlanName
IssueType
Jurisdiction
PaymentMode
PaymentAmt
PaymentMethod
FaceAmt
IndicatorCode
CurrentAmt
LifeParticipantRoleCode
TobaccoPremiumBasis
UnderwritingClass
ApplicationType
ApplicationJurisdiction
ReplacementInd
PremiumPaymentMethod
AnswersCompleteInd
SignaturesWitnessedInd
EveryonePresentInd
SplitCommInd
HoldingTypeCode
IssueDate
FaceAmt
RelationRoleCode
RelationRoleCode
PartyTypeCode
FullName
RelationRoleCode
PartyTypeCode
GovtID
GovtIDTC
FirstName
LastName
MarStat
Gender
BirthDate
Citizenship
EstSalary
SmokerStat
MeasureUnits
MeasureValue
MeasureUnits
MeasureValue
DriversLicenseNum
DriversLicenseState
BirthCountry
BirthJurisdictionTC
ImmigrationStatus
TobaccoFiveYearsInd
DriversLicenseInd
AddressTypeCode
Line1
City
AddressState
AddressStateTC
Zip
PhoneTypeCode
AreaCode
DialNumber
AddrLine
Occupation
EstIncomeRange
RelationRoleCode
RelationRoleCode
RelationRoleCode
PartyTypeCode
FirstName
LastName
AddressTypeCode
Line1
City
AddressState
AddressStateTC
Zip
PhoneTypeCode
AreaCode
DialNumber
AddrLine
RelationRoleCode
ExistingInsuranceInd
Party
PartyTypeCode
FullName
LastName
RelationRoleCode
InterestPercent
Sequence
RelationDescription
RelationRoleCode
RelationDescription
PartyTypeCode
FullName
CompanyProducerID
RelationRoleCode
InterestPercent
FormName
ProviderFormNumber
AttachmentBasicType
Description
AttachmentData
MimeTypeTC
SignatureRoleCode
SignatureDate
SignatureCity
SignatureState
SubmissionType
SignatureOK
RelationRoleCode
HoldingTypeCode
BankAcctType
AccountNumber
RoutingNum
BankName'''

file = """
<?xml version="1.0" encoding="UTF-8"?>
<TXLife Version="2.20.00">
    <UserAuthRequest>
        <UserLoginName>sgSurify</UserLoginName>
        <UserPswd>
            <CryptType>NONE</CryptType>
            <Pswd>Y2KtmR3L</Pswd>
        </UserPswd>
        <VendorApp>
            <VendorName VendorCode="564">Sureify</VendorName>
            <AppName>ApplyAndBuy</AppName>
            <AppVer>3.1</AppVer>
        </VendorApp>
    </UserAuthRequest>
    <TXLifeRequest PrimaryObjectID="Application_Holding">
        <TransRefGUID>N2FHOTDF-TQIL-Z8LB-FTQA-9UY1OZ73KMXD</TransRefGUID>
        <TransType tc="103">New Business Submission</TransType>
        <TransExeDate>2020-08-25</TransExeDate>
        <OLifE>
            <Holding id="Application_Holding">
                <HoldingTypeCode/>
                <Purpose tc="4">Personal</Purpose>
                <Policy>
                    <LineOfBusiness tc="1">Life</LineOfBusiness>
                    <ProductType tc="2">Term Life</ProductType>
                    <CarrierCode>Nationwide</CarrierCode>
                    <PlanName></PlanName>
                    <IssueType tc="4">Modeled Life</IssueType>
                    <Jurisdiction tc="1">AL</Jurisdiction>
                    <PaymentMode tc="4">Monthly</PaymentMode>
                    <PaymentAmt>23.98</PaymentAmt>
                    <PaymentMethod tc="7">Pre-Authorized Payment or Electronic Funds Transfer based on the product</PaymentMethod>
                    <Life>
                        <FaceAmt>100000</FaceAmt>
                        <Coverage>
                            <IndicatorCode tc="1">Base</IndicatorCode>
                            <CurrentAmt>100000</CurrentAmt>
                            <LifeParticipant PartyID="InsuredParty_1">
                                <LifeParticipantRoleCode tc="1">Primary Insured</LifeParticipantRoleCode>
                                <TobaccoPremiumBasis tc="1">Nonsmoker</TobaccoPremiumBasis>
                                <UnderwritingClass></UnderwritingClass>
                            </LifeParticipant>
                        </Coverage>
                    </Life>
                    <ApplicationInfo>
                        <ApplicationType tc="1">New</ApplicationType>
                        <ApplicationJurisdiction tc="1">AL</ApplicationJurisdiction>
                        <PrefLanguage/>
                        <ReplacementInd></ReplacementInd>
                        <ReplacementReason/>
                        <OLifEExtension VendorCode="564">
                            <PremiumPaymentMethod tc="2">Draft Initial and Future Payments</PremiumPaymentMethod>
                            <AnswersCompleteInd tc="1">True</AnswersCompleteInd>
                            <SignaturesWitnessedInd tc="1">True</SignaturesWitnessedInd>
                        </OLifEExtension>
                    </ApplicationInfo>
                    <RequirementInfo AppliesToPartyID="InsuredParty_1">
                        <ReqStatus/>
                        <ReqCategory/>
                    </RequirementInfo>
                    <OLifEExtension VendorCode="564">
                        <PolicyExtension>
                            <SimplifiedEligibleInd/>
                        </PolicyExtension>
                        <InterviewVendor/>
                    </OLifEExtension>
                </Policy>
                <OLifEExtension VendorCode="564">
                    <EveryonePresentInd tc="1">True</EveryonePresentInd>
                    <SplitCommInd tc="0">False</SplitCommInd>
                </OLifEExtension>
            </Holding>
            
            
            
            
            
            <Holding id="Holding_AppliedIns_1">
                <HoldingTypeCode/>
                <Policy CarrierPartyID="Party_Carrier_AppliedIns_1">
                    <Life>
                        <FaceAmt/>
                    </Life>
                </Policy>
                <OLifEExtension VendorCode="564">
                    <AppliedPurpose/>
                </OLifEExtension>
            </Holding>
            <Relation OriginatingObjectID="Application_Holding" RelatedObjectID="Holding_AppliedIns_1" id="Relation_AppliedIns_1">
                <RelationRoleCode/>
            </Relation>
            <Relation OriginatingObjectID="Holding_AppliedIns_1" RelatedObjectID="InsuredParty_1" id="Relation_InsuredAppliedPolicy_1">
                <RelationRoleCode/>
            </Relation>
            <Party id="Party_Carrier_AppliedIns_1">
                <PartyTypeCode/>
                <FullName/>
                <Organization/>
            </Party>
            <Relation OriginatingObjectID="Holding_AppliedIns_1" RelatedObjectID="Party_Carrier_AppliedIns_1" id="Relation_Carrier_AppliedIns_1">
                <RelationRoleCode/>
            </Relation>
            <Holding id="Holding_AppliedInsIn12Months_1">
                <HoldingTypeCode/>
                <Policy CarrierPartyID="Party_Carrier_AppliedInsIn12Months_1">
                    <Life>
                        <FaceAmt/>
                    </Life>
                </Policy>
            </Holding>
            <Relation OriginatingObjectID="Application_Holding" RelatedObjectID="Holding_AppliedInsIn12Months_1" id="Relation_AppliedInsIn12Months_1">
                <RelationRoleCode/>
                <RelationDescription/>
            </Relation>
            <Party id="Party_Carrier_AppliedInsIn12Months_1">
                <PartyTypeCode/>
                <FullName/>
                <Organization/>
            </Party>
            <Relation OriginatingObjectID="Holding_AppliedInsIn12Months_1" RelatedObjectID="Party_Carrier_AppliedInsIn12Months_1" id="Relation_Carrier_AppliedInsIn12Months_1">
                <RelationRoleCode/>
            </Relation>
            <Holding id="Banking_Holding">		
                <HoldingTypeCode tc="7">Banking</HoldingTypeCode>
                <Banking>	
                    <BankAcctType></BankAcctType>
                    <AccountNumber></AccountNumber>
                    <RoutingNum></RoutingNum>
                    <BankName></BankName>
                </Banking>	
            </Holding>
            <Party id="InsuredParty_1">
                <PartyTypeCode tc="1">Person</PartyTypeCode>
                <GovtID>111111111</GovtID>
                <GovtIDTC tc="1">SSN</GovtIDTC>
                <EstNetWorth/>
                <Person>
                    <FirstName>Sheetansh</FirstName>
                    <LastName>kumar</LastName>
                    <MarStat tc="2">Single</MarStat>
                    <Gender></Gender>
                    <BirthDate>1990-01-01</BirthDate>
                    <Age/>
                    <Citizenship tc="1">U.S.</Citizenship>
                    <EstSalary>1,111,111</EstSalary>
                    <SmokerStat tc="1">Nonsmoker</SmokerStat>
                    <Height2>
                        <MeasureUnits tc="2">US System Inches</MeasureUnits>
                        <MeasureValue>0</MeasureValue>
                    </Height2>
                    <Weight2>
                        <MeasureUnits tc="2">US System Inches</MeasureUnits>
                        <MeasureValue></MeasureValue>
                    </Weight2>
                    <DriversLicenseNum>1111111</DriversLicenseNum>
                    <DriversLicenseState tc="2">AK</DriversLicenseState>
                    <BirthCountry tc="1">United States of America</BirthCountry>
                    <BirthJurisdictionTC tc="2">AK</BirthJurisdictionTC>
                    <ImmigrationStatus tc="8">U.S. Citizen</ImmigrationStatus>
                    <OLifEExtension VendorCode="564">
                        <DriversLicenseInd tc="1">True</DriversLicenseInd>
                        <TobaccoFiveYearsInd tc="0">False</TobaccoFiveYearsInd>
                    </OLifEExtension>
                </Person>
                <Address>
                    <AddressTypeCode tc="1">Residence</AddressTypeCode>
                    <Line1>asdf</Line1>
                    <City>asdf</City>
                    <AddressState>AL</AddressState>
                    <AddressStateTC tc="1">AL</AddressStateTC>
                    <Zip>11111</Zip>
                </Address>
                <Phone>
                    <PhoneTypeCode tc="1">Home</PhoneTypeCode>
                    <AreaCode>111</AreaCode>
                    <DialNumber>1111111</DialNumber>
                    <PrefPhone/>
                </Phone>
                <EMailAddress>
                    <AddrLine>sheetansh@sureify.com</AddrLine>
                </EMailAddress>
                <Risk>
                    <AutoLicenseSuspension/>
                    <ExistingInsuranceInd tc="0">FALSE</ExistingInsuranceInd>
                    <RejectionInd/>
                    <BankruptcyInd/>
                    <WeightOneYearPrior/>
                    <WeightChangeReason/>
                    <RecentHospitalizationInd/>
                    <SeriousIllnessInd/>
                    <ReceivingDisabilityBenefitsInd/>
                    <AIDSInd/>
                    <CancerInd/>
                    <DiabetesInd/>
                    <RespiratoryInd/>
                    <StrokeInd/>
                    <TreatmentInAbsenceOfCondition/>
                    <OLifEExtension VendorCode="564">
                        <CriminalInd/>
                        <BackupInd/>
                        <ApplyInsuranceInd/>
                        <AppliedInsurance12MonthsInd/>
                        <LapseInsuranceInd/>
                        <AneurysmInd/>
                        <DepressionInd/>
                        <ColitisInd/>
                        <ReproductiveDisorderInd/>
                        <BloodDisorderInd/>
                        <ArthritisInd/>
                        <EyeDisorderInd/>
                        <OtherTestsInd/>
                        <MedicineInd/>
                        <HazardousActivityInd/>
                        <ContemplateMilitaryServiceInd/>
                        <MilitaryServiceInd/>
                        <ForeignTravelInd/>
                        <TerminateExistingInd/>
                        <FundsFromExistingInd/>
                        <FamilyIllnessInd/>
                        <AddictionInd/>
                        <ParamedCompleteInd/>
                        <AutoImmuneInd/>
                        <KidneyLiverDisorderInd/>
                    </OLifEExtension>
                </Risk>
                <Employment>
                    <Occupation>Accountant</Occupation>
                    <EmployerName/>
                </Employment>
                <OLifEExtension VendorCode="564">
                    <PartyExtension>
                        <EstIncomeRange>1,111,111</EstIncomeRange>
                    </PartyExtension>
                </OLifEExtension>
            </Party>
            <Relation OriginatingObjectID="Application_Holding" RelatedObjectID="InsuredParty_1" id="Relation_InsuredParty">
                <RelationRoleCode tc="32">Insured</RelationRoleCode>
            </Relation>
            <Relation OriginatingObjectID="Application_Holding" RelatedObjectID="InsuredParty_1" id="Relation_PartyOwner">
                <RelationRoleCode tc="8">Owner</RelationRoleCode>
            </Relation>
            <Party id="PartyPayor">
                <PartyTypeCode tc="1">Person</PartyTypeCode>
                <Person>
                    <FirstName></FirstName>
                    <LastName></LastName>
                </Person>
                <Address>
                    <AddressTypeCode tc="1">Residence</AddressTypeCode>
                    <Line1>asdf</Line1>
                    <City>asdf</City>
                    <AddressState>AL</AddressState>
                    <AddressStateTC tc="1">AL</AddressStateTC>
                    <Zip>11111</Zip>
                </Address>
                <Phone>
                    <PhoneTypeCode tc="1">Home</PhoneTypeCode>
                    <AreaCode></AreaCode>
                    <DialNumber></DialNumber>
                    <PrefPhone/>
                </Phone>
                <EMailAddress>
                    <AddrLine>sheetansh@sureify.com</AddrLine>
                </EMailAddress>
            </Party>
            <Relation OriginatingObjectID="Application_Holding" RelatedObjectID="PartyPayor" id="Relation_InsuredPayer">
                <RelationRoleCode/>
            </Relation>
            <Party id="Party_Beneficiary_1">
                <PartyTypeCode tc="1">Person</PartyTypeCode>
                <FullName></FullName>
                <GovtID/>
                <GovtIDTC/>
                <Person>
                    <FirstName/>
                    <LastName></LastName>
                    <BirthDate/>
                </Person>
                <Address>
                    <AddressTypeCode/>
                    <Line1/>
                    <City/>
                    <AddressState/>
                    <AddressStateTC/>
                    <Zip/>
                </Address>
                <Phone>
                    <PhoneTypeCode/>
                    <AreaCode/>
                    <DialNumber/>
                    <PrefPhone/>
                    <OLifEExtension VendorCode="564"/>
                </Phone>
                <OLifEExtension VendorCode="564">
                    <SplitPctInd/>
                </OLifEExtension>
            </Party>
            <Relation OriginatingObjectID="Application_Holding" RelatedObjectID="Party_Beneficiary_1" id="Relation_Beneficiary_1">
                <RelationRoleCode tc="34">Primary Beneficiary</RelationRoleCode>
                <InterestPercent></InterestPercent>
                <Sequence>1</Sequence>
            </Relation>
            <Relation OriginatingObjectID="InsuredParty_1" RelatedObjectID="Party_Beneficiary_1" id="Relation_InsuredBeneficiary_1">
                <RelationRoleCode tc="2">Wife</RelationRoleCode>
                <RelationDescription tc="2">Wife</RelationDescription>
            </Relation>
            <Party id="Party_Agent_1">
                <PartyTypeCode tc="2">Organization</PartyTypeCode>
                <FullName>FastTrack</FullName>
                <GovtID/>
                <GovtIDTC/>
                <Person>
                    <FirstName/>
                    <LastName/>
                </Person>
                <Phone>
                    <PhoneTypeCode/>
                    <AreaCode/>
                    <DialNumber/>
                    <PrefPhone/>
                </Phone>
                <Producer>
                    <CarrierAppointment>
                        <CompanyProducerID>99999999</CompanyProducerID>
                        <DistributionChannelInfo>
                            <DistributionChannelName/>
                        </DistributionChannelInfo>
                    </CarrierAppointment>
                </Producer>
                <EMailAddress>
                    <AddrLine/>
                </EMailAddress>
            </Party>
            <Relation OriginatingObjectID="Application_Holding" RelatedObjectID="Party_Agent_1" id="Relation_Application_Agent_1">
                <RelationRoleCode tc="37">Writing Agent</RelationRoleCode>
                <InterestPercent>100</InterestPercent>
            </Relation>
            <FormInstance id="|FORM_LOOKUP|">
                <FormName/>
                <ProviderFormNumber/>
                <Attachment>
                    <AttachmentBasicType/>
                    <Description/>
                    <AttachmentData/>
                    <MimeTypeTC/>
                    <SignatureInfo>
                        <SignatureRoleCode/>
                        <SignatureDate/>
                        <SignatureCity/>
                        <SignatureState/>
                        <SubmissionType/>
                        <SignatureOK/>
                    </SignatureInfo>
                </Attachment>
            </FormInstance>
            <Relation OriginatingObjectID="Application_Holding" RelatedObjectID="|FORM_LOOKUP|" id="Relation_|FORM_LOOKUP|">
                <RelationRoleCode/>
            </Relation>
            <OLifEExtension VendorCode="564">
                <Disconnected/>
            </OLifEExtension>
        </OLifE>
    </TXLifeRequest>
</TXLife>


"""


# a = """default excel content"""
# file = """file content"""

arr = a.split('\n')
# print(arr)
present = []
notpresent = []
for i in arr:
    find = "{}".format(i)
    if find in file:
        present.append(i)
    else:
        notpresent.append(i)
print(present)
print(notpresent)
print(len(notpresent))


