import sys
from google.auth.transport.requests import Request
from google.oauth2.credentials import Credentials
from google_auth_oauthlib.flow import InstalledAppFlow
from googleapiclient.discovery import build
from googleapiclient.errors import HttpError

# If modifying these scopes, delete the file token.json.
SCOPES = ['https://www.googleapis.com/auth/spreadsheets']

# The ID and range of a sample spreadsheet.
SAMPLE_SPREADSHEET_ID = '1zMDxrkGiis9USY-jtFnpVVw4Fel1Zs-2gkLWOXGOuzg'
SAMPLE_RANGE_NAME = "'Update history'!A1:A8"


def update_values(spreadsheet_id, range_name, value_input_option, _values):
    print(f"{SAMPLE_RANGE_NAME}")
    creds = Credentials.from_authorized_user_file('token.json', SCOPES)

    if not creds or not creds.valid:
        if creds and creds.expired and creds.refresh_token:
            creds.refresh(Request())

        # Save the credentials for the next run
        with open('token.json', 'w') as token:
            token.write(creds.to_json())

    try:
        service = build('sheets', 'v4', credentials=creds)
        values = _values  # Use the provided values parameter
        body = {
            'values': values
        }
        result = service.spreadsheets().values().append(
            spreadsheetId=spreadsheet_id, range=range_name,
            valueInputOption=value_input_option, body=body).execute()
        return result
    except HttpError as error:
        print(f"An error occurred: {error}")
        return error


if __name__ == '__main__':
    args = [string[1:] for string  in sys.argv]
    update_values(SAMPLE_SPREADSHEET_ID, SAMPLE_RANGE_NAME, 'USER_ENTERED',
                  [
                      args[1:]
                  ])