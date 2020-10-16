String validationEmail(String value) {
  String pattern =
      r'^(([^<>()[\]\\.,;:\s@\"]+(\.[^<>()[\]\\.,;:\s@\"]+)*)|(\".+\"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$';
  RegExp regExp = new RegExp(pattern);
  if (value.length == 0) {
    return "Email is Required";
  } else if (!regExp.hasMatch(value)) {
    return "Invalid Email";
  } else {
    return null;
  }
}

// Call in text form field
TextFormField(
              style: TextStyle(
                  fontSize: 14,
                  color: kCharcoalColor,
                  fontWeight: FontWeight.w400),
              keyboardType: TextInputType.emailAddress,
              validator: validationEmail,
              initialValue: data.patient.email,
              onSaved: (String val) {
                email = val;
              },
            ),