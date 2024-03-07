import os.path

from google.auth.transport.requests import Request
from google.oauth2.credentials import Credentials
from google_auth_oauthlib.flow import InstalledAppFlow
from googleapiclient.discovery import build
from googleapiclient.errors import HttpError

# If modifying these scopes, delete the file token.json.
SCOPES = ["https://www.googleapis.com/auth/spreadsheets.readonly"]

# The ID and range of a sample spreadsheet.
SAMPLE_SPREADSHEET_ID = "1zMDxrkGiis9USY-jtFnpVVw4Fel1Zs-2gkLWOXGOuzg"
#SAMPLE_RANGE_NAME = "test!A2:E"

def main():
#   """Shows basic usage of the Sheets API.
#   Prints values from a sample spreadsheet.
#   """
#   creds = None
#   # The file token.json stores the user's access and refresh tokens, and is
#   # created automatically when the authorization flow completes for the first
#   # time.
#   if os.path.exists("token.json"):
#     creds = Credentials.from_authorized_user_file("token.json", SCOPES)
#   # If there are no (valid) credentials available, let the user log in.
#   if not creds or not creds.valid:
#     if creds and creds.expired and creds.refresh_token:
#       creds.refresh(Request())
#     else:
#       flow = InstalledAppFlow.from_client_secrets_file(
#           "credentials.json", SCOPES
#       )
#       creds = flow.run_local_server(port=0)
#     # Save the credentials for the next run
#     with open("token.json", "w") as token:
#       token.write(creds.to_json())

  try:
    creds = None
    if os.path.exists("token.json"):
        creds = Credentials.from_authorized_user_file("token.json", SCOPES)

    service = build("sheets", "v4", credentials=creds)

    # Call the Sheets API
    sheet = service.spreadsheets()
    # result = (
    #     sheet.values()
    #     .get(spreadsheetId=SAMPLE_SPREADSHEET_ID, range=SAMPLE_RANGE_NAME)
    #     .execute()
    # )

    sheet_metadata = service.spreadsheets().get(spreadsheetId=SAMPLE_SPREADSHEET_ID).execute()
    properties = sheet_metadata.get('sheets')
    result = []
    for  item in properties:
      # if item.get("properties").get('title') == 'SHEET_TITILE':
      #     sheet_id = (item.get("properties").get('sheetId'))
      print(item.get("properties").get('title'))


    return item.get("properties").get('title');


    # if not sheet_id:
    #   print("No data found.")
    #   return

    # print("Name, Major:")
    # for row in sheet_id:
    #   # Print columns A and E, which correspond to indices 0 and 4.
    #   print(f"sheet_id")
  except HttpError as err:
    print(err)


if __name__ == "__main__":
  main()
